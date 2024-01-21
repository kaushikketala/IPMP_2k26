#include <iostream>
using namespace std;

// Function to swap even and odd bits
unsigned int swapBits(unsigned int x) {
    for (int i = 0; i < 32; i += 2) {
        // Find i th bit
        int i_bit = (x >> i) & 1;

        // Find i+1 th bit
        int i_1_bit = (x >> (i + 1)) & 1;

        // Remove i_bit
        x = x - (i_bit << i)
            // Remove i+1 th bit
            - (i_1_bit << (i + 1))
            // Put i_bit at i+1 location
            + (i_bit << (i + 1))
            // Put i+1 bit at i location
            + (i_1_bit << i);
    }
    return x;
}

// Driver code
int main() {
    // Input the value of x from the user
    unsigned int x;
    cout << "Enter a number: ";
    cin >> x;

    // Function Call and Output
    cout << "After swapping even and odd bits: " << swapBits(x) << endl;

    return 0;
}
