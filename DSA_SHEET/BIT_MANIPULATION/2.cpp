#include <iostream>
using namespace std;

// Function to reverse bits of num
unsigned int reverseBits(unsigned int num) {
    unsigned int NO_OF_BITS = sizeof(num) * 8;
    unsigned int reverse_num = 0;

    for (int i = 0; i < NO_OF_BITS; i++) {
        if ((num & (1 << i)))
            reverse_num |= 1 << ((NO_OF_BITS - 1) - i);
    }

    return reverse_num;
}

int main() {
    unsigned int x;

    // Input the value of x from the user
    cout << "Enter a number: ";
    cin >> x;

    cout << "Reversed bits: " << reverseBits(x) << endl;

    return 0;
}
