#include <iostream>
#include <algorithm>
using namespace std;

bool areAnagram(const string& str1, const string& str2) {
    int n1 = str1.length();
    int n2 = str2.length();

    if (n1 != n2)
        return false;

    string sortedStr1 = str1;
    string sortedStr2 = str2;

    sort(sortedStr1.begin(), sortedStr1.end());
    sort(sortedStr2.begin(), sortedStr2.end());

    return sortedStr1 == sortedStr2;
}

int main() {
    string str1, str2;

    // Input the first string from the user
    cout << "Enter the first string: ";
    cin >> str1;

    // Input the second string from the user
    cout << "Enter the second string: ";
    cin >> str2;

    // Function call and print the result
    if (areAnagram(str1, str2)) {
        cout << "The two strings are anagrams of each other" << endl;
    } else {
        cout << "The two strings are not anagrams of each other" << endl;
    }

    return 0;
}
