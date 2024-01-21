#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

bool canMatch(char a, char b) {
    return (a == b || b == '.');
}

bool isMatch(const string& s, const string& p) {
    int lS = s.length();
    int lP = p.length();
    vector<vector<bool>> F(lS + 1, vector<bool>(lP + 1, false));
    F[0][0] = true;

    for (int i = 0; i <= lS; i++) {
        for (int j = 1; j <= lP; j++) {
            if (i > 0 && F[i-1][j-1] && canMatch(s[i-1], p[j-1])) {
                // matches one character, index of both string and pattern move forward by 1
                F[i][j] = true;
                continue;
            }

            if (i > 0 && j > 1 && F[i-1][j] && canMatch(s[i-1], p[j-2]) && p[j-1] == '*') {
                // matches the situation when the next char in the string is the same as the char before the '*' in the pattern
                // pre-match: string xxxCyyy, pattern mmmC*nnn, xxx matches mmmC*
                // current match: xxxC matches mmmC*
                F[i][j] = true;
                continue;
            }

            if (j > 1 && F[i][j-2] && p[j-1] == '*') {
                // matches the situation when the next two chars in the pattern are in the form of C*
                // pre-match: string xxxyyy, pattern mmmC*nnn, xxx matches mmm
                // current match: xxx matches mmmC*
                F[i][j] = true;
                continue;
            }
        }
    }

    return F[lS][lP];
}

int main() {
    string s, p;

    // Input the string from the user
    cout << "Enter the string: ";
    cin >> s;

    // Input the pattern from the user
    cout << "Enter the pattern: ";
    cin >> p;

    bool result = isMatch(s, p);

    cout << "The pattern " << (result ? "matches" : "does not match") << " the string." << endl;

    return 0;
}
