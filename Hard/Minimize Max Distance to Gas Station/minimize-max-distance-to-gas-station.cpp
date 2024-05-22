//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
        bool isPossible(vector<int> &stations,double mid,int k){
        int total=0;
        for(int i=1;i<stations.size();i++){
            int dis = stations[i]-stations[i-1];
            total+=ceil(dis/mid)-1;
        }
        return total<=k;
    }
    double findSmallestMaxDist(vector<int> &stations, int k) {
        // Code here
        int n=stations.size();
        double low=0,high=stations[n-1]-stations[0],mid=0,ans=stations[n-1]-stations[0];
        while(high-low>=1e-6){
            mid=(low+high)/2;
            if(isPossible(stations,mid,k)){
                ans=mid;
                high=mid;
            }
            else low=mid;
        }
        return ans;

        
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> stations(n);
        for (int i = 0; i < n; i++) {
            cin >> stations[i];
        }
        int k;
        cin >> k;
        Solution obj;
        cout << fixed << setprecision(2) << obj.findSmallestMaxDist(stations, k)
             << endl;
    }
    return 0;
}
// } Driver Code Ends