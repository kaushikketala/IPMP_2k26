#include <iostream>
using namespace std;

int ic_strcmp(string s1, string s2) {
    int i;
    for (i = 0; s1[i] && s2[i]; ++i) {
        if (s1[i] == s2[i] || (s1[i] ^ 32) == s2[i])
            continue;
        else
            break;
    }

    if (s1[i] == s2[i])
        return 0;

    if ((s1[i] | 32) < (s2[i] | 32))
        return -1;
    return 1;
}

int main() {
    string str1, str2;

    // Input the first string from the user
    cout << "Enter the first string: ";
    getline(cin, str1);

    // Input the second string from the user
    cout << "Enter the second string: ";
    getline(cin, str2);

    // Call the ic_strcmp function on the input strings and print the result
    cout << "ret: " << ic_strcmp(str1, str2) << endl;

    return 0;
}
