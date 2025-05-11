//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

// User function Template for C++

class Solution {
  public:
    int kthLargest(vector<int> &arr, int k) {
        // code here
        int n=arr.size();
        vector<int>pre(n+1,0);
        
        for(int i=0;i<n;i++) pre[i+1]=pre[i]+arr[i];
        priority_queue<int,vector<int>,greater<int>>mH;
        
        for(int i=0;i<n;i++){
            for(int j=i+1;j<=n;j++){
                int sum= pre[j]-pre[i];
                if(mH.size()<k) mH.push(sum);
                else if(sum>mH.top()){
                    mH.pop();
                    mH.push(sum);
                }
             }
        }
        return mH.top();
    }
};


//{ Driver Code Starts.

int main() {
    string ts;
    getline(cin, ts);
    int t = stoi(ts);
    while (t--) {
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        string ks;
        getline(cin, ks);
        int k = stoi(ks);
        Solution obj;
        int res = obj.kthLargest(arr, k);
        cout << res << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends