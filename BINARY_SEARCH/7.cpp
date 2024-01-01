#include <iostream>
#include <climits>
using namespace std;

double myPow(double x, int n) {
    if (n == 0) {
        return 1.0;
    }

    if (n < 0) {
        x = 1 / x;
        // Handle potential overflow when n = INT_MIN
        if (n == INT_MIN) {
            x *= x;
            n++;
        }
        n = -n;
    }

    double result = 1.0;
    while (n > 0) {
        if (n % 2 == 1) {
            result *= x;
        }
        x *= x;
        n /= 2;
    }

    return result;
}

int main() {
    double x;
    int n;

    cout << "Enter the base (x): ";
    cin >> x;

    cout << "Enter the exponent (n): ";
    cin >> n;

    double result = myPow(x, n);

    cout << "Result of pow(" << x << ", " << n << "): " << result << endl;

    return 0;
}
