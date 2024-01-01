#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

class TimeMap {
public:
    TimeMap() {}

    void set(string key, string value, int timestamp) {
        data[key].emplace_back(timestamp, value);
    }

    string get(string key, int timestamp) {
        if (data.find(key) == data.end()) {
            return "";
        }

        const vector<pair<int, string>>& values = data[key];

        // Binary search to find the largest timestamp prev <= timestamp
        int left = 0;
        int right = values.size() - 1;

        while (left <= right) {
            int mid = left + (right - left) / 2;

            if (values[mid].first == timestamp) {
                return values[mid].second;
            } else if (values[mid].first < timestamp) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }

        // At the end of the loop, left is the index of the largest timestamp_prev <= timestamp
        if (left > 0) {
            return values[left - 1].second;
        } else {
            return "";
        }
    }

private:
    unordered_map<string, vector<pair<int, string>>> data;
};

int main() {
    // Input variables
    string key, value;
    int timestamp;

    // Example usage:
    TimeMap timeMap;

    // Input "set" operations
    cout << "Enter 'set' operations (key, value, timestamp):" << endl;
    while (cin >> key >> value >> timestamp) {
        timeMap.set(key, value, timestamp);
    }

    // Input "get" operations
    cout << "Enter 'get' operations (key, timestamp):" << endl;
    while (cin >> key >> timestamp) {
        cout << "Result: " << timeMap.get(key, timestamp) << endl;
    }

    return 0;
}
