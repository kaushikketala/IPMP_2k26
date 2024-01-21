#include <iostream> 
using namespace std; 
 void permute(string& a, int l, int r) 
{ 
    // Base case 
    if (l == r) 
        cout << a << endl; 
    else { 
        
        for (int i = l; i <= r; i++) {
            swap(a[l], a[i]); 
            permute(a, l + 1, r);
            swap(a[l], a[i]); 
        } 
    } 
} 
  
// Driver Code 
int main() 
{ 
    cout<<"enetr your string: ";
    string str; 
    cin>>str;
    int n = str.size(); 
  
    // Function call 
    permute(str, 0, n - 1); 
    return 0; 
} 