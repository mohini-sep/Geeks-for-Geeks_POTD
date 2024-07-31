//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution {
  public:

    string longestCommonPrefix(vector<string> arr) {
        // your code here
        string temp = arr[0];
        int i=0,j=0;
        while(i<temp.length()){
            for(j=0;j<arr.size();j++){
                if(temp[i]!=arr[j][i])break;
            }
            if(j!=arr.size())break;
            i++;
        }
        if(i==0)return "-1";
        return temp.substr(0,i);
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<string> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        string number;
        while (ss >> number) {
            arr.push_back(number);
        }

        Solution ob;
        cout << ob.longestCommonPrefix(arr) << endl;
    }
}

// } Driver Code Ends