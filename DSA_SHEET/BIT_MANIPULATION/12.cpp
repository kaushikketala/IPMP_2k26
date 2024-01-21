#include <iostream>
using namespace std;

// Function to perform nibble-wise swap
unsigned int swapNibbles(unsigned int num) {
    // Extract the left and right nibbles
    unsigned int leftNibble = (num & 0xF0) >> 4;
    unsigned int rightNibble = (num & 0x0F) << 4;

    // Combine the swapped nibbles
    return leftNibble | rightNibble;
}

int main() {
    // Input the value from the user
    unsigned int num;
    cout << "Enter an unsigned integer: ";
    cin >> num;

    // Perform nibble-wise swap
    unsigned int result = swapNibbles(num);

    // Output the result
    cout << "Original number: " << num << endl;
    cout << "Number after nibble-wise swap: " << result << endl;

    return 0;
}
