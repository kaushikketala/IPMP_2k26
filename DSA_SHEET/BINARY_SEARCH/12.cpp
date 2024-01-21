#include <iostream>
#include <vector>
#include <algorithm>
#include<numeric>
using namespace std;

int shipWithinDays(const vector<int>& weights, int days) {
    int left = *max_element(weights.begin(), weights.end());
    int right = accumulate(weights.begin(), weights.end(), 0);

    while (left < right) {
        int mid = left + (right - left) / 2;
        int daysNeeded = 1;
        int currentWeight = 0;

        for (int weight : weights) {
            if (currentWeight + weight > mid) {
                daysNeeded++;
                currentWeight = 0;
            }
            currentWeight += weight;
        }

        if (daysNeeded > days) {
            // The weight capacity is too small, increase it
            left = mid + 1;
        } else {
            // The weight capacity is sufficient, try a smaller one
            right = mid;
        }
    }

    return left;
}

int main() {
    int n;
    cout << "Enter the number of packages: ";
    cin >> n;

    vector<int> weights(n);
    cout << "Enter the weights of the packages: ";
    for (int i = 0; i < n; ++i) {
        cin >> weights[i];
    }

    int days;
    cout << "Enter the number of days: ";
    cin >> days;

    int result = shipWithinDays(weights, days);

    cout << "Minimum weight capacity required: " << result << endl;

    return 0;
}
