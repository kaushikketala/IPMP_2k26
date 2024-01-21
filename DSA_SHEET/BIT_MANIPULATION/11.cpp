#include <iostream>
using namespace std;

// A utility function to check whether n is a power of 2 or not.
// See http://goo.gl/17Arj
int isPowerOfTwo(unsigned n) {
    return n && (!(n & (n - 1)));
}

// Returns position of the only set bit in 'n'
int findPosition(unsigned n) {
    if (!isPowerOfTwo(n))
        return -1;

    unsigned i = 1, pos = 1;

   
    
    // at the same position
    while (!(i & n)) {
        // Unset the current bit and set the next bit in 'i'
        i = i << 1;

        // increment position
        ++pos;
    }

    return pos;
}


int main(void) {
    // Input the value of n from the user
    unsigned n;
    cout << "Enter a number: ";
    cin >> n;

    int pos = findPosition(n);
    (pos == -1) ? cout << "n = " << n << ", Invalid number" << endl : cout << "n = " << n << ", Position " << pos << endl;

    return 0;
}
