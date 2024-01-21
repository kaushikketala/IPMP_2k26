#include <iostream>
#include <vector>
#define NO_OF_CHAR 256
using namespace std;

int* getCountArray(const string& str2) {
    int* count = new int[NO_OF_CHAR]();
    
    for (char c : str2) {
        count[c]++;
    }

    return count;
}

string removeDirtyChars(const string& str1, const string& str2) {
    int* count = getCountArray(str2);
    string res;

    for (char c : str1) {
        if (count[c] == 0) {
            res.push_back(c);
        }
    }

    delete[] count;
    return res;
}

int main() {
    string str1, str2;

    // Input the first string from the user
    cout << "Enter the first string: ";
    getline(cin, str1);

    // Input the second string from the user
    cout << "Enter the second string (contains characters to be removed): ";
    getline(cin, str2);

    // Function call and print the result
    cout << "Result after removing dirty characters: " << removeDirtyChars(str1, str2) << endl;

    return 0;
}
