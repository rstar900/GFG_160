//{ Driver Code Starts
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
        
      
        // Keep track of the minimum value at which a stock can be bought along 
        // with maximum profit that can be made at that time instance
        int buy_val = prices[0];
        int max_profit = 0;
        
        for (int i{}; i < prices.size(); ++i) {
           // If the value is smaller, then we have found a new buy_val
           if (prices[i] < buy_val) {
               buy_val = prices[i];
           }
           // Otherwise in case the value is larger, we compare the profit made
           // with value so far
           else if (prices[i] > buy_val) {
               max_profit = std::max(max_profit, prices[i] - buy_val);
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
        vector<int> prices;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            prices.push_back(number);
        }

        Solution ob;
        int ans = ob.maximumProfit(prices);
        cout << ans << endl;
    }
    return 0;
}

// } Driver Code Ends
