#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    int search(const std::vector<int>& nums, int target) {
        int left = 0, right = nums.size() - 1;

        while (left <= right) {
            int mid = left + (right - left) / 2;

            if (nums[mid] == target) {
                return mid; // Target found
            } else if (nums[mid] < target) {
                left = mid + 1; // Search in the right half
            } else {
                right = mid - 1; // Search in the left half
            }
        }

        return -1; // Target not found
    }
};

int main() {
    Solution solution;
    vector<int> nums1;
    cout<<"enter the number of elements: ";
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        int k;
        cout<<"enter the element in index "<<i<<endl;
        cin>>k;
        nums1.push_back(k);
    }
    int target1;
    cout<<"enter the target: ";
    cin>>target1;
   cout<< "Output: " << solution.search(nums1, target1) <<endl;


    return 0;
}