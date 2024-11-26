//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    // Function to find the majority elements in the array
    vector<int> findMajority(vector<int>& arr) {
        // We will be using the Moore's voting algorithm for 2 possible candidates
        // In this case since k = 3 in n/k, so there are possible k-1 i.e. 2 possible candidates
        // Hence the result vector will contain maximum of 2 elements
        vector<int> result;
        int n = arr.size();
        
        // Just return the result with that element, in case there is only 1 element
        if (n == 1) {
            result.push_back(arr[0]);
        
        } else {
            // Initialize the candidates and their counts as invalid or lowest possible values
            int candidate_1{-1}, candidate_2{-1}, count_1{}, count_2{}; 
            
            for (int i{}; i < n; ++i) {
                // Increase the respective candidate in case it is equal to one of them
                if (arr[i] == candidate_1) {
                    ++count_1;
                } else if (arr[i] == candidate_2) {
                    ++count_2;
                }
                
                // If that is not the case, check which if any element is 0 and
                // replace that one, giving first one as prio to be replaced in case of tie
                else if (count_1 == 0) {
                    candidate_1 = arr[i]; count_1 = 1;
                } else if (count_2 == 0) {
                    candidate_2 = arr[i]; count_2 = 1;
                }
                
                // If none of them is 0, and since the element is not equal to and
                // has not replaced any one of them, will lead to decrement in their
                // counts
                else {
                    --count_1; --count_2; 
                }
            }
            
            // Now we need to check whether the frequencies of the candidates are 
            // more than n/3, if that is the case, append the candidate to result
            int freq_1{}, freq_2{};
            
            for (int i{}; i < n; ++i) {
                
                if (arr[i] == candidate_1) {
                    ++freq_1;
                }
                if (arr[i] == candidate_2) {
                    ++freq_2;
                }
            }
            
            if (freq_1 > n / 3) {
                result.push_back(candidate_1);
            }
            if (freq_2 > n / 3) {
                result.push_back(candidate_2);
            }
            
            // Now swap the elements, if they are in decreasing order
            if (result.size() == 2 && result[0] > result[1]) {
                int temp = result[0]; result[0] = result[1]; result[1] = temp;
            }
        }
      
        return result;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {

        string s;
        getline(cin, s);
        stringstream ss(s);
        vector<int> nums;
        int num;
        while (ss >> num) {
            nums.push_back(num);
        }
        Solution ob;
        vector<int> ans = ob.findMajority(nums);
        if (ans.empty()) {
            cout << "[]";
        } else {
            for (auto &i : ans)
                cout << i << " ";
        }
        cout << "\n";
    }
    return 0;
}
// } Driver Code Ends
