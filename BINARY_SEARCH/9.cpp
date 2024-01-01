#include <iostream>
#include <vector>

using namespace std;

int findPeakElement(const vector<int>& nums) {
    int left = 0, right = nums.size() - 1;

    while (left < right) {
        int mid = left + (right - left) / 2;

        if (nums[mid] > nums[mid + 1]) {
            // The peak is in the left half (including mid)
            right = mid;
        } else {
            // The peak is in the right half (excluding mid)
            left = mid + 1;
        }
    }

    return left;
}

int main() {
    int n;
    cout << "Enter the size of the array: ";
    cin >> n;

    vector<int> nums(n);
    cout << "Enter the elements of the array: ";
    for (int i = 0; i < n; ++i) {
        cin >> nums[i];
    }

    int peakIndex = findPeakElement(nums);

    cout << "Output: " << peakIndex << endl;

    return 0;
}
