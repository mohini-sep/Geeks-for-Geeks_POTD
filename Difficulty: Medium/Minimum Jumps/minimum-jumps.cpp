//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int minJumps(vector<int>& arr) {
        // code here
        int n=arr.size();
        if(n==1) return 0;
        if(arr[0]==0) return -1;
        
        int jump=1, jumpEnd=arr[0], maxReach=arr[0];
        for(int i=1;i<n;i++){
            if(i==n-1) return jump;
            
            maxReach=max(maxReach, i+arr[i]);
            
            if(i==jumpEnd){
                if(i==maxReach) return -1;
                
                jump++;
                jumpEnd=maxReach;
            }
        }
        return -1;
    }
};



//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        int n, i, j;
        vector<int> arr;
        string ip;
        int number;
        getline(cin, ip);
        stringstream ss(ip);

        while (ss >> number) {
            arr.push_back(number);
        }
        Solution obj;
        cout << obj.minJumps(arr) << endl << "~\n";
    }
    return 0;
}

// } Driver Code Ends