//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int helper(int ind, int sum, vector<int>&coins, vector<vector<int>>&dp){
        if(sum==0) return 1;
        if(ind==coins.size()) return 0;
        
        if(dp[ind][sum]!=-1) return dp[ind][sum];
        
        int take=0, not_take=0;
        if(coins[ind]<=sum) take=helper(ind, sum-coins[ind], coins, dp);
        
        not_take= helper(ind+1, sum, coins, dp);
        
        return dp[ind][sum] = take + not_take;
    }
  
    int count(vector<int>& coins, int sum) {
        // code here.
        int n=coins.size();
        
        vector<vector<int>>dp(n,vector<int>(sum+1, -1));
        
        return helper(0, sum, coins, dp);
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
        int sum;
        cin >> sum;
        cin.ignore();
        Solution ob;
        cout << ob.count(arr, sum) << endl;
        cout << "~" << endl;
    }

    return 0;
}

// } Driver Code Ends