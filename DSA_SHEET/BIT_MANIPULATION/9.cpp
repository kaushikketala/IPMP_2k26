#include <iostream>
#include <cmath>
using namespace std;

class gfg {
public:
    unsigned int getFirstSetBitPos(int n) {
        return log2(n & -n) + 1;
    }
};

// Driver code
int main() {
    gfg g;
    
    // Input the value of n from the user
    int n;
    cout << "Enter a number: ";
    cin >> n;

    // Calculate and output the position of the first set bit
    cout << "Position of the first set bit: " << g.getFirstSetBitPos(n) << endl;

    return 0;
}
