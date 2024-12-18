//{ Driver Code Starts
// Initial function template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    bool check(vector<int>&arr, int k, int mid){
        int number=1, pages=0;
        for(int i=0;i<arr.size();i++){
            if(arr[i]>mid) return false;
            if(pages+arr[i]>mid){
                pages=arr[i];
                number++;
            }
            else{
                pages+=arr[i];
            }
        }
        if(number<=k) return true;
        return false;
    }
    
    int findPages(vector<int> &arr, int k) {
        // code here
        if(arr.size()<k) return -1;
        int lo=0, hi=0;
        for(auto it:arr) hi+=it;
        int ans=-1;
        while(lo<=hi){
            int mid=(lo+hi)/2;
            if(check(arr, k, mid)){
                ans=mid;
                hi=mid-1;
            }
            else{
                lo=mid+1;
            }
        }
        return ans;
        // code here
    }
};

//{ Driver Code Starts.

int main() {
    int test_case;
    cin >> test_case;
    cin.ignore();
    while (test_case--) {

        int d;
        vector<int> arr, brr, crr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        getline(cin, input);
        ss.clear();
        ss.str(input);
        while (ss >> number) {
            crr.push_back(number);
        }
        d = crr[0];
        int n = arr.size();
        Solution ob;
        int ans = ob.findPages(arr, d);
        cout << ans << endl;

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends