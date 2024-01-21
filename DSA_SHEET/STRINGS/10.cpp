#include <iostream>
#include <unordered_map>
using namespace std;

int main() {
    string inputString;

    // Input a string from the user
    cout << "Enter a string: ";
    getline(cin, inputString);

    if (inputString.empty()) {
        cout << "EMPTY STRING" << endl;
        return 0;
    }

    unordered_map<char, int> charCount;
    char firstNonRepeatingChar = ' ';
    bool found = false;

    for (char c : inputString) {
        charCount[c]++;
    }

    for (char c : inputString) {
        if (charCount[c] == 1) {
            firstNonRepeatingChar = c;
            found = true;
            break;
        }
    }

    if (found) {
        cout << "First non-repeating character is " << firstNonRepeatingChar << endl;
    } else {
        cout << "All characters are repeating" << endl;
    }

    return 0;
}
