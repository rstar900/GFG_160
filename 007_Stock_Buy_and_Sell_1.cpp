//{ Driver Code Starts
// Initial template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int maximumProfit(vector<int> &prices) {
        // If there is only one element in the array, then profit is 0
        if (prices.size() == 1) {
            return 0;
        }
        
        // Otherwise the maximum profit is the sum of local minima and maxima 
        // We buy at local minima, and sell at local maxima
        
        int local_max = prices[0];
        int local_min = prices[0];
        int max_profit = 0;
        bool bought = false;
        
        for (int i{}; i < prices.size(); ++i) {
            // If we found a local minima, we need to look for local maxima next
            // only if the stock is not already bought
            if (prices[i] < prices[i+1] && !bought) {
                local_min = prices[i];
                bought = true;
            }
            
            // If we have already bought the stock and we found the local maxima
            // we sell and hence calculate the difference and add it to max profit
            else if (prices[i] > prices[i+1] && bought) {
                local_max = prices[i];
                max_profit += (local_max - local_min);
                bought = false;
            }
            
            // In case we reached the end of array, just check
            // if the element is larger then the last found local minimum
            // and consider it as the local_maxima
            else if (i == prices.size() - 1 && prices[i] > local_min && bought) {
                max_profit += (prices[i] - local_min);
            } 
            
        }
        
        return max_profit;
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
        int n = arr.size();
        Solution ob;
        int res = ob.maximumProfit(arr);
        cout << res;

        cout << "\n";
    }
    return 0;
}
// } Driver Code Ends
