#include <iostream>
using namespace std;

int add(int a, int b) {
    // for loop will start from 1 and move till the value of
    // second number, first number(a) is incremented in for
    // loop
    for (int i = 1; i <= b; i++)
        a++;
    return a;
}

int main() {
    int num1, num2;

    // Input the values of num1 and num2 from the user
    cout << "Enter the first number: ";
    cin >> num1;

    cout << "Enter the second number: ";
    cin >> num2;

    // Calculate the sum using the add function
    int result = add(num1, num2);

    // Output the result
    cout << "The sum of " << num1 << " and " << num2 << " is: " << result << endl;

    return 0;
}
