#include <iostream>
using namespace std;

/* Function to get the number of set bits in the binary
   representation of a positive integer n */
unsigned int countSetBits(unsigned int n) {
    unsigned int count = 0;
    while (n) {
        count += n & 1;
        n >>= 1;
    }
    return count;
}

int main() {
    unsigned int i;

    // Input the value of i from the user
    cout << "Enter a number: ";
    cin >> i;

    // Print the number of set bits
    cout << "Number of set bits: " << countSetBits(i) << endl;

    return 0;
}
