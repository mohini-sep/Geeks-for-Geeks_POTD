//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int findMin(vector<int>& arr) {
        // complete the function here
        int ans=arr[0], lo=0, hi=arr.size()-1;
        
        while(lo<=hi){
            int mid=(lo+hi)/2;
            ans=min(ans, arr[mid]);
            
            if(arr[lo]<=arr[mid]){
                ans=min(ans, arr[lo]);
                lo=mid+1;
            }
            else if(arr[mid]<=arr[hi]){
                hi=mid-1;
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    string ts;
    getline(cin, ts);
    int t = stoi(ts);

    Solution ob;
    while (t--) {
        string line;
        getline(cin, line);
        stringstream ss(line);
        vector<int> nums;
        int num;
        while (ss >> num) {
            nums.push_back(num);
        }
        cout << ob.findMin(nums) << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends