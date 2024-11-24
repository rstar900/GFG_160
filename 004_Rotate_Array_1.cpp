//{ Driver Code Starts
// Initial function template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
  
  // Helper function
  void reverseArr(vector<int>& arr, int start, int end) {
      // do in place reversal only if there start != end, and start < end
      if (start != end && start < end) {
          while (start < end) {
              // swap the elements at current start and end positions
              int temp = arr[start];
              arr[start] = arr[end];
              arr[end] = temp;
              ++start; --end; // bring them one step closer for next iteration
          }
      }
  }

    // Function to rotate an array by d elements in counter-clockwise direction.
    void rotateArr(vector<int>& arr, int d) {
        // d should be greater than 0 for any rotation
        if (d > 0) {
            // We use the reversal algorithm for this problem
            
            // Reverse the first d elements
            reverseArr(arr, 0, d % arr.size() - 1);
            
            // Reverse the remaining elements
            reverseArr(arr, d % arr.size(), arr.size() - 1);
            
            // Reverse the whole array
            reverseArr(arr, 0, arr.size() - 1);
        }
    }
};

//{ Driver Code Starts.

int main() {
    int test_case;
    cin >> test_case;
    cin.ignore();
    while (test_case--) {

        int d;
        vector<int> arr, brr, crr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        getline(cin, input);
        ss.clear();
        ss.str(input);
        while (ss >> number) {
            crr.push_back(number);
        }
        d = crr[0];
        int n = arr.size();
        Solution ob;
        // calling rotateArr() function
        ob.rotateArr(arr, d);

        // printing the elements of the array
        for (int i = 0; i < n; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends
