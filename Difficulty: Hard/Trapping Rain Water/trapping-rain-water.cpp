//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int maxWater(vector<int> &arr) {
        // code here
        int n=arr.size();
        vector<int>v(n, 0);
        int maxi=0;
        for(int i=n-1;i>=0;i--){
            maxi=max(maxi, arr[i]);
            v[i]=maxi;
        }
        
        maxi=0;
        int ans=0;
        
        for(int i=0;i<n;i++){
            maxi=max(maxi, arr[i]);
            
            ans+=max(0, min(maxi, v[i])-arr[i]);
        }
        
        return ans;
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

        // Read first array
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }

        Solution ob;
        int res = ob.maxWater(arr);

        cout << res << endl << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends