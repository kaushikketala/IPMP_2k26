#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool areDistinct(const string& str, int i, int j) {
    vector<bool> visited(256, false);

    for (int k = i; k <= j; k++) {
        if (visited[str[k]])
            return false;
        visited[str[k]] = true;
    }

    return true;
}

int longestUniqueSubsttr(const string& str) {
    int n = str.size();
    int res = 0;

    for (int i = 0; i < n; i++)
        for (int j = i; j < n; j++)
            if (areDistinct(str, i, j))
                res = max(res, j - i + 1);

    return res;
}

int main() {
    string inputStr;

    // Input the string from the user
    cout << "Enter a string: ";
    cin >> inputStr;

    int length = longestUniqueSubsttr(inputStr);

    cout << "The length of the longest non-repeating character substring is: " << length << endl;

    return 0;
}
