#include <iostream>
#include <cstring>
using namespace std;

void printRLE(const string& str) {
    int n = str.length();
    for (int i = 0; i < n; i++) {

        // Count occurrences of current character
        int count = 1;
        while (i < n - 1 && str[i] == str[i + 1]) {
            count++;
            i++;
        }

        // Print character and its count
        cout << str[i] << count;
    }
}

int main() {
    string str;

    // Input the string from the user
    cout << "Enter a string: ";
    cin >> str;

    // Call the printRLE function on the input string
    printRLE(str);

    return 0;
}
