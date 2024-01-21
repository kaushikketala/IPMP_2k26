#include <iostream>
#include <cstdlib>
using namespace std;

int main() {
    int val;
    char strn[100];

    // Input a string from the user
    cout << "Enter a string containing digits: ";
    cin >> strn;

    // Convert the string to an integer
    val = atoi(strn);

    // Print the original string and the converted integer value
    cout << "String value = " << strn << endl;
    cout << "Integer value = " << val << endl;

    return 0;
}
