#include <iostream>
#include <vector>
using namespace std;

void print(vector<int> a, int n) {
    for (int i = 0; i <= n; i++) 
        cout << a[i] << " ";    
    cout << endl;
}

// Sorts a[] in descending order using bubble sort.
void sort(vector<int>& a, int n) {
    for (int i = n; i >= 0; i--) 
        for (int j = n; j > n - i; j--) 
            if (a[j] > a[j - 1]) 
                swap(a[j], a[j - 1]);
    print(a, n);
}

int main() {
    int n;

    // Input size of the vector
    cout << "Enter the size of the vector: ";
    cin >> n;

    vector<int> a;

    // Input elements of the vector
    cout << "Enter the elements of the vector: ";
    for (int i = 0; i < n; i++) {
        int element;
        cin >> element;
        a.push_back(element);
    }

    sort(a, n - 1);
    
    return 0;
}
