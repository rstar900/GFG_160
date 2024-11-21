//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    void reverseArray(vector<int> &arr) {
        // For only 1 element, simply return
        if (arr.size() > 1) {
            // Create 2 variables i and j
            // i increments from the beginning
            // j decrements from the end
            // swap the elements at both of their indices
            // as long as they do not cross each other
            
            int i{}, j{arr.size()-1};
            
            while (i < j) {
                // swap
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
                
                ++i; --j;
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
        ob.reverseArray(arr);
        for (int i = 0; i < arr.size(); i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
        cout << "~" << endl;
    }
    return 0;
}
// } Driver Code Ends
