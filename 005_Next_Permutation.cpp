//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

// Helper function to reverse the array
void reverse(vector<int>& arr, int start, int end) {
    while (start < end) {
        int temp = arr[start];
        arr[start] = arr[end];
        arr[end] = temp;
        start++; end--;
    }
}


class Solution {
  public:
    void nextPermutation(vector<int>& arr) {
        int n = arr.size();
        
    // No need to do anything if there is only 1 element
    if (n == 1) {
        return; 
    }
    
    // If 2 elements, then simply return the reverse
    if (n == 2) {
        return reverse(arr, 0, 1);
    }
    
    // Find the rightmost pivot element
    // This is the element whose next element is increasing
    // Since the valid value and position can never be -1, we start that to indicate emptiness 
    int pivot_pos = -1;
    int pivot_val = -1;
    
    // Start finding pivot element from rightmost position
    for (int i{n - 2}; i >= 0; --i) {
        if (arr [i + 1] > arr[i]) {
            // we found the pivot element
            pivot_val = arr[i];
            pivot_pos = i;
            break;
        }
    }
    
    // If no pivot element is found, simply reverse the whole array
    if (pivot_pos == -1) {
        return reverse(arr, 0, n - 1);
        
    } else {
        // Otherwise find the next rightmost element 
        // which is just greater than pivot element
        // and replace it with that
        for (int i{n - 1}; i >= pivot_pos + 1; --i) {
            // Since the elements to the right of pivot element
            // are in decreasing order, we just need to find the first
            // such element
           if (arr[i] > pivot_val) {
               // Swap them
               int temp = arr[i];
               arr[i] = pivot_val;
               arr[pivot_pos] = temp;
               // reverse the array from next element to pivot to the end of the array
               return reverse(arr, pivot_pos + 1, n - 1);
           } 
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
        ob.nextPermutation(arr);
        for (int i = 0; i < n; i++) {
            cout << arr[i] << " ";
        }
        cout << "\n";
    }
    return 0;
}

// } Driver Code Ends
