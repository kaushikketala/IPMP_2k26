#include <iostream>
using namespace std;

// Function that counts set bits
int countSetBits(int n) {
    int count = 0;
    while (n > 0) {
        count++;
        n &= (n - 1);
    }
    return count;
}

// Function that returns the count of flipped bits
int FlippedCount(int a, int b) {
    // Return count of set bits in a XOR b
    return countSetBits(a ^ b);
}

int main() {
    int a, b;

    // Input the values of a and b from the user
    cout << "Enter the value of a: ";
    cin >> a;
    cout << "Enter the value of b: ";
    cin >> b;

    // Function call and output the result
    cout << "Flipped count: " << FlippedCount(a, b) << endl;

    return 0;
}
