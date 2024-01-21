#include <iostream>
#include <vector>

using namespace std;

bool searchMatrix(const vector<vector<int>>& matrix, int target) {
    int m = matrix.size();
    if (m == 0) {
        return false;
    }

    int n = matrix[0].size();
    if (n == 0) {
        return false;
    }

    int left = 0, right = m * n - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;
        int midValue = matrix[mid / n][mid % n];

        if (midValue == target) {
            return true;
        } else if (midValue < target) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }

    return false;
}

int main() {
    int m, n;
    cout << "Enter the number of rows (m) in the matrix: ";
    cin >> m;

    cout << "Enter the number of columns (n) in the matrix: ";
    cin >> n;

    vector<vector<int>> matrix(m, vector<int>(n));
    cout << "Enter the elements of the matrix in non-decreasing order: ";
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> matrix[i][j];
        }
    }

    int target;
    cout << "Enter the target value: ";
    cin >> target;

    bool result = searchMatrix(matrix, target);

    cout << "Output: " << (result ? "true" : "false") << endl;

    return 0;
}
