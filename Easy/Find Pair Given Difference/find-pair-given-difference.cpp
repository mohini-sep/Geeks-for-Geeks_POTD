//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

class Array {
  public:
    template <class T>
    static void input(vector<T> &A, int n) {
        for (int i = 0; i < n; i++) {
            scanf("%d ", &A[i]);
        }
    }

    template <class T>
    static void print(vector<T> &A) {
        for (int i = 0; i < A.size(); i++) {
            cout << A[i] << " ";
        }
        cout << endl;
    }
};


// } Driver Code Ends

#include <vector>
#include <algorithm>

class Solution {
public:
    int findPair(int n, int x, std::vector<int> &arr) {
        // Step 1: Sort the array
        std::sort(arr.begin(), arr.end());
        
        // Step 2: Initialize two pointers
        int i = 0, j = 1;
        
        // Step 3: Iterate with the two pointers
        while (i < n && j < n) {
            if (i != j && std::abs(arr[j] - arr[i]) == x) {
                return 1;
            } else if (arr[j] - arr[i] < x) {
                j++;
            } else {
                i++;
            }
        }
        
        // Step 4: Return -1 if no such pair is found
        return -1;
    }
};



//{ Driver Code Starts.

int main() {
    int t;
    scanf("%d ", &t);
    while (t--) {

        int n;
        scanf("%d", &n);

        int x;
        scanf("%d", &x);

        vector<int> arr(n);
        Array::input(arr, n);

        Solution obj;
        int res = obj.findPair(n, x, arr);

        cout << res << endl;
    }
}

// } Driver Code Ends