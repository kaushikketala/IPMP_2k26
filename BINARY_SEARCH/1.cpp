#include <iostream>
using namespace std;
class Solution {
public:
    int mySqrt(int x) {
        if (x == 0 || x == 1) {
            return x;
        }

        int left = 1, right = x, result = 0;

        while (left <= right) {
            int mid = left + (right - left) / 2;

            if (mid <= x / mid) {
                left = mid + 1;
                result = mid;
            } else {
                right = mid - 1;
            }
        }

        return result;
    }
};

int main() {
    Solution solution;
    
    // Example 1
    int x1 ;
    cout<<"enter any value: "<<endl;
    cin>>x1;
    cout << "Input: " << x1 << "\nOutput: " << solution.mySqrt(x1) <<endl;

   
    return 0;
}