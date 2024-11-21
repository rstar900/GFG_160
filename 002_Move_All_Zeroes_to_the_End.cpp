//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++
class Solution {
  public:
    void pushZerosToEnd(vector<int>& arr) {
        // If there is only one element, no need to do anything
        if (arr.size() <= 1) {
            return;
            
        } else {
            int n = arr.size();
            
            // We divide the array into a partition of non-zero elements (left)
            // and zeroes (right), filling non-zero partition, and writing zeroes
            // in the remaining spaces
            
            // For keeping the track of non-zero partition's next vacant position 
            // and it's count
            int j{}; 
            
            for (int i{}; i < n; ++i) {
                if (arr[i] != 0) {
                    arr[j++] = arr[i];
                }
            }
            
            // Get the count of zeroes to be filled
            int zeroes{n-j};
            
            // Fill the zeroes from the end of the array
            for (int i{n-1}; i >= 0 && zeroes >= 1; --i) {
                arr[i] = 0;
                --zeroes;
            }
        }
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        Solution ob;
        int n = arr.size();
        ob.pushZerosToEnd(arr);
        for (int i = 0; i < n; i++) {
            cout << arr[i] << " ";
        }
        cout << "\n";
    }
    return 0;
}
// } Driver Code Ends
