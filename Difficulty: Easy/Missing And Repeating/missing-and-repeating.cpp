//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
class Solution {
  public:
    vector<int> findTwoElement(vector<int>& arr) {
        // code here
         int n=arr.size();
        long long S=((long long)n*(n+1))/2;
        long long Sq=(((long long)n*(n+1)*(2*n+1)))/6;
        long Si=0,Sqi=0;
        for(int i=0;i<n;i++){
            Si+=arr[i];
            Sqi+=((long long)arr[i]*arr[i]);
        }
        long long X_minus_Y=S-Si;
        long long X_plus_Y=(Sq-Sqi)/X_minus_Y;
        long long miss=(X_minus_Y+X_plus_Y)/2;
        long long rep=X_plus_Y-miss;
        return {rep,miss};
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        string input;
        int num;
        vector<int> arr;
        getline(cin, input);
        stringstream s2(input);
        while (s2 >> num) {
            arr.push_back(num);
        }
        Solution ob;
        auto ans = ob.findTwoElement(arr);
        cout << ans[0] << " " << ans[1] << "\n";

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends