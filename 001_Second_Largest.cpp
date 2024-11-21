//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
// User function template for C++
class Solution {
  public:
    // Function returns the second
    // largest elements
    int getSecondLargest(vector<int> &arr) {
        
        if (arr.size() == 1 || arr.empty()) {
            // In case of 0 or 1 elements, no second largest possible
            return -1;
            
        } else {
            
            // Set the value of largest and second largest to a value
            // less than the elements in the array
            int max = -1, max_2 = -1;
            
            for (int i{}; i < arr.size(); ++i) {
                
                if (arr[i] > max) {
                    // Since we found new max, we first set max_2 
                    // to current max and then uate the max
                    max_2 = max;
                    max = arr[i];
                    
                } else if (arr[i] < max && arr[i] > max_2){
                    // Might be possible, that there is a number
                    // greater than max_2 but less than max
                    max_2 = arr[i];
                }
            }
            
            return max_2;
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
        int ans = ob.getSecondLargest(arr);
        cout << ans << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends
