#include <iostream>
using namespace std;
#define CHARBIT 8

/* This function will return the absolute value of n */
unsigned int getAbs(int n) {
    int const mask = n >> (sizeof(int) * CHARBIT - 1);
    return ((n + mask) ^ mask);
}

/* Driver program to test the function */
int main() {
    int n;

    // Input the value of n from the user
    cout << "Enter an integer value: ";
    cin >> n;

    // Output the absolute value of n
    cout << "Absolute value of " << n << " is " << getAbs(n) << endl;

    return 0;
}
