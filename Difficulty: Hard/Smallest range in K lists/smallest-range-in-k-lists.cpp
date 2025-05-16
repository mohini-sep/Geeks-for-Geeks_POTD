//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    vector<int> findSmallestRange(vector<vector<int>>& arr) {
        // code here
        int n = arr.size();    
        int m = arr[0].size();
        
        priority_queue<pair<int, pair<int, int>>,
                       vector<pair<int, pair<int, int>>>,
                       greater<>> minHeap;
                       
        int maxVal   = INT_MIN;
        int maxEl    = -1;     
        int minEl    = -1;     
        int minRange = INT_MAX;

        for (int i = 0; i < n; i++) {
            minHeap.push({ arr[i][0], { i, 0 } });
            maxVal = max(maxVal, arr[i][0]); 
        }

        
        while (true) {
            auto top = minHeap.top(); 
            minHeap.pop();

            int minVal = top.first;         
            int row    = top.second.first;  
            int col    = top.second.second; 

            if (maxVal - minVal < minRange) {
                minRange = maxVal - minVal;
                minEl    = minVal;
                maxEl    = maxVal;
            }

            if (col + 1 == m) {
                break;
            }

            int nextVal = arr[row][col + 1];
            minHeap.push({ nextVal, { row, col + 1 } });

            // Update maxVal if needed
            maxVal = max(maxVal, nextVal);
        }

        return { minEl, maxEl };
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        vector<vector<int>> arr(k, vector<int>(n));

        for (int i = 0; i < k; i++)
            for (int j = 0; j < n; j++)
                cin >> arr[i][j];

        Solution obj;
        vector<int> range = obj.findSmallestRange(arr);
        cout << range[0] << " " << range[1] << "\n";
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends