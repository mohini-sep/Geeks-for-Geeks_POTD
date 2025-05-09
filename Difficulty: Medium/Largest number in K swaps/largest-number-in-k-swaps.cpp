//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends



class Solution {
  public:
    // Function to find the largest number after k swaps.
    string ans = "";
    void solve(int idx, int n, string str, int k){
        if(k == 0 || idx >= n){
            ans = max(ans, str);
            return;
        }
        
        
        for(int i = idx + 1; i<n; i++){
            if(str[i] > str[idx]){
                swap(str[i], str[idx]);
                solve(idx + 1, n, str, k - 1);
                swap(str[i], str[idx]);
            }
        }
        
        solve(idx + 1, n, str, k);
        
    }
    string findMaximumNum(string str, int k)
    {
        int n = str.length();
        solve(0, n, str, k);
        return ans;
    }
};


//{ Driver Code Starts.

int main() {
    int t, k;
    string str;

    cin >> t;
    while (t--) {
        cin >> k >> str;
        Solution ob;
        cout << ob.findMaximumNum(str, k) << endl;

        cout << "~"
             << "\n";
    }
    return 0;
}

// } Driver Code Ends