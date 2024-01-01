#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool canAchieve(const vector<int>& nums, int maxOperations, int penalty) {
    for (int ball : nums) {
        maxOperations -= (ball - 1) / penalty;
        if (maxOperations < 0) {
            return false;
        }
    }
    return true;
}

int minimumPenalty(const vector<int>& nums, int maxOperations) {
    int left = 1, right = *max_element(nums.begin(), nums.end());

    while (left < right) {
        int mid = left + (right - left) / 2;

        if (canAchieve(nums, maxOperations, mid)) {
            right = mid;
        } else {
            left = mid + 1;
        }
    }

    return left;
}

int main() {
    int n;
    cout << "Enter the number of bags: ";
    cin >> n;

    vector<int> nums(n);
    cout << "Enter the number of balls in each bag: ";
    for (int i = 0; i < n; ++i) {
        cin >> nums[i];
    }

    int maxOperations;
    cout << "Enter the maximum number of operations: ";
    cin >> maxOperations;

    int result = minimumPenalty(nums, maxOperations);

    cout << "Minimum possible penalty: " << result << endl;

    return 0;
}
