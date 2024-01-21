#include <iostream>
#include <climits>

using namespace std;

bool containsAllCharacters(string& substr, string& pattern) {
    int count[256] = { 0 };

    for (char ch : pattern)
        count[ch]++;

    for (char ch : substr) {
        if (count[ch] > 0)
            count[ch]--;
    }

    for (int i = 0; i < 256; i++) {
        if (count[i] > 0)
            return false;
    }

    return true;
}

string findSmallestSubstring(const string& str, const string& pattern) {
    int len_str = str.length();
    int len_pattern = pattern.length();
    string smallestSubstring = "";

    int minLength = INT_MAX;

    for (int i = 0; i < len_str; i++) {
        for (int j = i; j < len_str; j++) {
            string substr = str.substr(i, j - i + 1);

            if (containsAllCharacters(substr, pattern)) {
                int currentLength = substr.length();

                if (currentLength < minLength) {
                    minLength = currentLength;
                    smallestSubstring = substr;
                }
            }
        }
    }

    return smallestSubstring;
}

int main() {
    string inputStr, pattern;

    // Input the string from the user
    cout << "Enter a string: ";
    getline(cin, inputStr);

    // Input the pattern from the user
    cout << "Enter a pattern: ";
    getline(cin, pattern);

    string result = findSmallestSubstring(inputStr, pattern);

    cout << "Smallest substring containing all characters of the pattern: \"" << result << "\"" << endl;

    return 0;
}
