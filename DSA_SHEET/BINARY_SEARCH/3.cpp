#include <iostream>
#include <vector>

using namespace std;

int countNegatives(vector<vector<int>>& grid) {
    int m = grid.size();
    int n = grid[0].size();

    int count = 0;
    int row = 0;
    int col = n - 1;

    while (row < m && col >= 0) {
        if (grid[row][col] < 0) {
            // If the current element is negative, increment the count and move to the next column.
            count++;
            col--;
        } else {
            // If the current element is non-negative, move to the next row.
            row++;
        }
    }

    return count;
}

int main() {
    int m, n;

    // Input matrix dimensions
    cout << "Enter the number of rows: ";
    cin >> m;
    cout << "Enter the number of columns: ";
    cin >> n;

    // Input matrix elements
    vector<vector<int>> grid(m, vector<int>(n));
    cout << "Enter the matrix elements:" << endl;
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> grid[i][j];
        }
    }

    // Calculate and display the result
    cout << "Output: " << countNegatives(grid) << endl;

    return 0;
}
