#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <iterator>

const int CHUNK_SIZE = 5; // Adjust this based on your available memory and dataset size

void merge(std::vector<int>& arr, int left, int mid, int right) {
    std::vector<int> temp(right - left + 1);
    int i = left, j = mid + 1, k = 0;

    while (i <= mid && j <= right) {
        if (arr[i] < arr[j]) {
            temp[k++] = arr[i++];
        } else {
            temp[k++] = arr[j++];
        }
    }

    while (i <= mid) {
        temp[k++] = arr[i++];
    }

    while (j <= right) {
        temp[k++] = arr[j++];
    }

    for (k = 0; k < temp.size(); ++k) {
        arr[left + k] = temp[k];
    }
}

void mergeSort(std::vector<int>& arr, int left, int right) {
    if (left < right) {
        int mid = (left + right) / 2;
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);
        merge(arr, left, mid, right);
    }
}

void externalSort(const std::string& inputFileName, const std::string& outputFileName) {
    std::ifstream inputFile(inputFileName, std::ios::binary);
    std::ofstream outputFile(outputFileName, std::ios::binary);

    std::vector<int> buffer(CHUNK_SIZE);

    while (inputFile) {
        // Read a chunk of data
        inputFile.read(reinterpret_cast<char*>(buffer.data()), buffer.size() * sizeof(int));
        std::size_t bytesRead = inputFile.gcount();

        // Sort the chunk
        buffer.resize(bytesRead / sizeof(int));
        mergeSort(buffer, 0, buffer.size() - 1);

        // Write the sorted chunk to a temporary file
        outputFile.write(reinterpret_cast<const char*>(buffer.data()), bytesRead);
    }

    inputFile.close();
    outputFile.close();
}

void mergeSortedChunks(const std::vector<std::string>& chunkFiles, const std::string& outputFileName) {
    std::ofstream outputFile(outputFileName, std::ios::binary);

    std::vector<std::ifstream> chunkReaders;
    std::vector<int> currentValues;

    // Open all chunk files
    for (const auto& chunkFile : chunkFiles) {
        chunkReaders.emplace_back(chunkFile, std::ios::binary);
        int value;
        if (chunkReaders.back() >> value) {
            currentValues.push_back(value);
        }
    }

    while (!currentValues.empty()) {
        // Find the minimum value among the current values
        auto minIt = std::min_element(currentValues.begin(), currentValues.end());
        int minValue = *minIt;

        // Write the minimum value to the output file
        outputFile.write(reinterpret_cast<const char*>(&minValue), sizeof(int));

        // Read the next value from the corresponding chunk file
        auto chunkIndex = std::distance(currentValues.begin(), minIt);
        int nextValue;
        if (chunkReaders[chunkIndex] >> nextValue) {
            currentValues[chunkIndex] = nextValue;
        } else {
            // Remove the exhausted chunk file
            currentValues.erase(minIt);
            chunkReaders[chunkIndex].close();
            chunkReaders.erase(chunkReaders.begin() + chunkIndex);
        }
    }

    outputFile.close();
}

int main() {
    std::string inputFileName = "input.dat";
    std::string outputFileName = "output.dat";

    // Assuming you have an input file named "input.dat" with integers

    // External sorting: Sort each chunk of data in memory
    externalSort(inputFileName, outputFileName);

    // Merge the sorted chunks into a single sorted file
    std::vector<std::string> chunkFiles = {"output.dat"}; // Adjust this based on the number of chunks
    mergeSortedChunks(chunkFiles, "final_output.dat");

    std::cout << "External sorting completed. Result saved in 'final_output.dat'.\n";

    return 0;
}
