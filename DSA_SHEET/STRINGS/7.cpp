#include <iostream>
#include <algorithm>
using namespace std;

// Define a function to calculate the factorial of a given number using recursion
int fact(int n) {
    // Base case: if n is 0 or 1, return 1
    if (n <= 1) {
        return 1;
    }
    // Recursive case: return n times the factorial of n-1
    return n * fact(n - 1);
}

// Define a function to calculate the rank of a given string in lexicographic permutation order
int findRank(string str) {
    // Calculate the length of the input string
    int n = str.length();
    // Initialize the rank as 1
    int rank = 1;

    // Loop through each character of the string
    for (int i = 0; i < n; i++) {
        // Initialize a variable to count the number of characters less than str[i]
        int count = 0;

        // Loop through the characters after str[i]
        for (int j = i + 1; j < n; j++) {
            // If str[i] is greater than str[j], increment the count variable
            if (str[i] > str[j]) {
                count++;
            }
        }

        // Update the rank based on the count of characters less than str[i]
        // multiplied by the factorial of the number of remaining characters
        rank += count * fact(n - i - 1);
    }

    // Return the final rank of the input string
    return rank;
}

// Define the main function
int main() {
    // Define a test string
    string str;

    // Input the string from the user
    cout << "Enter a string: ";
    cin >> str;

    // Call the findRank function on the input string and print the result
    cout << "Rank of the string: " << findRank(str) << endl;

    // Return 0 to indicate successful program completion
    return 0;
}
