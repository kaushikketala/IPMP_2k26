#include <iostream>
using namespace std;

// Unsets the rightmost set bit of n and returns the result
int fun(unsigned int n) {
    return n & (n - 1);
}

// Driver code
int main() {
    unsigned int n;

    // Input the value of n from the user
    cout << "Enter an unsigned integer value: ";
    cin >> n;

    // Output the result after unsetting the rightmost set bit
    cout << "The number after unsetting the rightmost set bit: " << fun(n) << endl;

    return 0;
}
