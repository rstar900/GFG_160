//{ Driver Code Starts
// Initial function template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
  
  int gcd(int a, int b) {
      if (b == 0) {
          return a;
      } else {
          return gcd(b, a % b);
      }
  }

    // Function to rotate an array by d elements in counter-clockwise direction.
    void rotateArr(vector<int>& arr, int d) {
        
        // Only rotate if there are more than 1 element and d > 0
        if (d > 0 && arr.size() > 1) {
            int n = arr.size();
            
            // We will use the juggling algorithm
            // For this we first need to determine the number of cycles for which the
            // outer loop will run. This is the GCD of n and d % n
            int cycles = gcd(n, d % n);
            
            for (int i{}; i < cycles; ++i) {
                // We store the first element into a temporary, as it will be replaced
                // and put to the new location after the traversal of the current cycle 
                // is complete
                int first_element = arr[i];
    
                // The inner loop starts replacing elements from position of the ith 
                // element with each increment being d % n apart
                // stopping only if the next position is equal to i
                int current_pos = i; // Start from ith position
                while (true) {
                    // Check for the stopping condition before replacement
                    // if true, we break
                    int next_pos = (current_pos + d) % n;
                    if (next_pos == i) {
                        break;
                    }
                    // Otherwise keep replacing the current element by next element
                    // and change the current position to the next for next iteration
                    // of the inner loop
                    arr[current_pos] = arr[next_pos];
                    current_pos = next_pos;
                }
                
                // Replace the last element of the cycle by the first element
                arr[current_pos] = first_element;
            }
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
