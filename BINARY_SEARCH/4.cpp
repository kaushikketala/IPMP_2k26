#include <iostream>
#include <vector>

using namespace std;

int peakIndexInMountainArray(vector<int>& arr) {
    int left = 0;
    int right = arr.size() - 1;

    while (left < right) {
        int mid = left + (right - left) / 2;

        if (arr[mid] < arr[mid + 1]) {
            // We are ascending the mountain, so the peak is on the right side
            left = mid + 1;
        } else {
            // We are descending the mountain, so the peak is on the left side
            right = mid;
        }
    }

    // At the end of the loop, left and right will be pointing to the peak index
    return left;
}

int main() {
    // Example usage:
    vector<int> arr1;
    printf("enter the number of elements: ");
    int n ;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cout<<"enter the element in index "<<i<<endl;
        int k;
        cin>>k;
        arr1.push_back(k);
    }
    cout<<"for given array,Output: " << peakIndexInMountainArray(arr1) << endl;  

    return 0;
}
