//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    // Function to find the majority elements in the array
    vector<int> findMajority(vector<int>& arr) {
        // Your code goes here.
           int f1 = 0, f2 = 0;
        int num1 = INT_MIN, num2 = INT_MIN;
    
        // First pass: Identify potential majority elements
        for (int num : arr) {
            if (num == num1) {
                ++f1;
            } else if (num == num2) {
                ++f2;
            } else if (f1 == 0) {
                num1 = num;
                ++f1;
            } else if (f2 == 0) {
                num2 = num;
                ++f2;
            } else {
                --f1;
                --f2;
            }
        }
    
        // Reset frequencies for the second pass
        f1 = 0;
        f2 = 0;
    
        // Second pass: Verify the frequencies
        for (int num : arr) {
            if (num == num1) {
                ++f1;
            } else if (num == num2) {
                ++f2;
            }
        }
    
        int n = arr.size();
        vector<int> res;
    
        // Check if num1 and num2 are valid majority elements
        if (f1 > n / 3) {
            res.push_back(num1);
        }
        if (f2 > n / 3) {
            res.push_back(num2);
        }
    
        // Sort the result if it contains two elements
        if (res.size() == 2 && res[0] > res[1]) {
            swap(res[0], res[1]);
        }
    
        return res;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {

        string s;
        getline(cin, s);
        stringstream ss(s);
        vector<int> nums;
        int num;
        while (ss >> num) {
            nums.push_back(num);
        }
        Solution ob;
        vector<int> ans = ob.findMajority(nums);
        if (ans.empty()) {
            cout << "[]";
        } else {
            for (auto &i : ans)
                cout << i << " ";
        }
        cout << "\n";
    }
    return 0;
}
// } Driver Code Ends