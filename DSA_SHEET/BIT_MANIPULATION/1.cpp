#include <iostream>
#include <cmath>

// Function to check if x is a power of 2
bool isPowerOfTwo(int n) {
    if (n == 0)
        return false;

    return (ceil(log2(n)) == floor(log2(n)));
}

// Driver code
int main() {
    int n;

    // Input the value of n from the user
    std::cout << "Enter a number: ";
    std::cin >> n;

    // Function call
    isPowerOfTwo(n) ? std::cout << "Yes" << std::endl
                    : std::cout << "No" << std::endl;

    return 0;
}
