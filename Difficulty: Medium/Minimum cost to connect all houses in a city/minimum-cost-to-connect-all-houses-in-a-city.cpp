//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int minCost(vector<vector<int>>& houses) {
        // code here
        int n = houses.size();
        vector<pair<int, pair<int, int>>> edges;
        
        // Generate all possible edges with Manhattan distance
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                int cost = abs(houses[i][0] - houses[j][0]) + abs(houses[i][1] - houses[j][1]);
                edges.push_back({cost, {i, j}});
            }
        }
        
        // Sort edges based on cost
        sort(edges.begin(), edges.end());

        // DSU for Kruskal's Algorithm
        vector<int> parent(n), rank(n, 0);
        iota(parent.begin(), parent.end(), 0); // Initialize parent[i] = i

        function<int(int)> find = [&](int x) {
            return parent[x] == x ? x : parent[x] = find(parent[x]);
        };
        
        auto union_sets = [&](int u, int v) {
            int pu = find(u), pv = find(v);
            if (pu != pv) {
                if (rank[pu] > rank[pv]) parent[pv] = pu;
                else if (rank[pv] > rank[pu]) parent[pu] = pv;
                else parent[pv] = pu, rank[pu]++;
                return true;
            }
            return false;
        };

        // Find the MST
        int minCost = 0, edgesUsed = 0;
        for (auto& edge : edges) {
            int cost = edge.first;
            int u = edge.second.first;
            int v = edge.second.second;
            
            if (union_sets(u, v)) {
                minCost += cost;
                edgesUsed++;
                if (edgesUsed == n - 1) break; // Stop when we have enough edges
            }
        }
        
        return minCost;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> edges;

        for (int i = 0; i < n; ++i) {
            vector<int> temp;
            for (int j = 0; j < 2; ++j) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            edges.push_back(temp);
        }

        Solution obj;

        cout << obj.minCost(edges);
        cout << "\n";
        cout << "~" << endl;
    }
}

// } Driver Code Ends