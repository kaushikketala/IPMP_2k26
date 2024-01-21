#include<iostream>

using namespace std;
#define INT_BITS 32

class gfg {
public:
    /* Function to left rotate n by d bits */
    int leftRotate(int n, unsigned int d) {
        return (n << d) | (n >> (INT_BITS - d));
    }

    /* Function to right rotate n by d bits */
    int rightRotate(int n, unsigned int d) {
        return (n >> d) | (n << (INT_BITS - d));
    }
};

/* Driver code */
int main() {
    gfg g;
    int n, d;

    // Input the values of n and d from the user
    cout << "Enter the value of n: ";
    cin >> n;
    cout << "Enter the value of d: ";
    cin >> d;

    // Output the results of left and right rotation
    cout << "Left Rotation of " << n <<
            " by " << d << " is " << g.leftRotate(n, d) << endl;
    cout << "Right Rotation of " << n <<
            " by " << d << " is " << g.rightRotate(n, d) << endl;

    return 0;
}
