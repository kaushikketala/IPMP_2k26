#include <iostream>
#include <climits>

using namespace std;

int divide(int dividend, int divisor) {
    // Handle overflow cases
    if (dividend == INT_MIN && divisor == -1) {
        return INT_MAX;
    }

    // Determine the sign of the result
    int sign = (dividend < 0) ^ (divisor < 0) ? -1 : 1;

    // Take the absolute values to simplify the calculations
    long long absDividend = llabs(dividend);
    long long absDivisor = llabs(divisor);

    // Initialize the quotient
    long long quotient = 0;

    // Perform the division using repeated subtraction
    while (absDividend >= absDivisor) {
        absDividend -= absDivisor;
        quotient++;
    }

    // Apply the sign to the quotient
    quotient *= sign;

    // Ensure the result is within the 32-bit signed integer range
    if (quotient < INT_MIN) {
        return INT_MIN;
    } else if (quotient > INT_MAX) {
        return INT_MAX;
    }

    return static_cast<int>(quotient);
}

int main() {
    int dividend, divisor;

    cout << "Enter the dividend: ";
    cin >> dividend;

    cout << "Enter the divisor: ";
    cin >> divisor;

    int result = divide(dividend, divisor);

    cout << "Output: " << result << endl;

    return 0;
}
