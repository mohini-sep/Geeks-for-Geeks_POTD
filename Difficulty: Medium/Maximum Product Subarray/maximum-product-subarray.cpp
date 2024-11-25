//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    // Function to find maximum product subarray
    int maxProduct(vector<int> &arr) {
        // Your Code Here
        int left=1,right=1;
        int n=arr.size();
        int maxLeft=INT_MIN,maxRight=INT_MIN;
        
        for(int i=0;i<n;i++){
            left*=arr[i];
            maxLeft=max(maxLeft,left);
            if(left==0) left=1;
        }
        for(int i=n-1;i>=0;i--){
            right*=arr[i];
            maxRight=max(maxRight,right);
            if(right==0) right=1;
        }
        return max(maxLeft,maxRight);
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        // int n, i;
        // cin >> n;
        // vector<int> arr(n);
        // for (i = 0; i < n; i++) {
        //     cin >> arr[i];
        // }

        vector<int> arr;
        string input;

        // Read array
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        Solution ob;
        auto ans = ob.maxProduct(arr);
        cout << ans << "\n";

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends