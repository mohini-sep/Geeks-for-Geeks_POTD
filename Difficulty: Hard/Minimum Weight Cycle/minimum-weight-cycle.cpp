//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
     int findMinCycle(int V, vector<vector<int>>& edges) {
        const int INF = 1e9;
        vector<vector<pair<int, int>>> adj(V);
        
        for (auto& edge : edges) {
            adj[edge[0]].push_back({edge[1], edge[2]});
            adj[edge[1]].push_back({edge[0], edge[2]});
        }

        int minCycle = INF;

        auto dijkstra = [&](int src, int forbidden_u, int forbidden_v) {
            priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
            vector<int> dist(V, INF);
            dist[src] = 0;
            pq.push({0, src});

            while (!pq.empty()) {
                pair<int, int> topElement = pq.top(); 
                int d = topElement.first;
                int u = topElement.second;
                pq.pop();

                if (d > dist[u]) continue;

                for (auto& neighbor : adj[u]) {
                    int v = neighbor.first, w = neighbor.second;
                    
                    if ((u == forbidden_u && v == forbidden_v) || (u == forbidden_v && v == forbidden_u))
                        continue; 

                    if (dist[u] + w < dist[v]) {
                        dist[v] = dist[u] + w;
                        pq.push({dist[v], v});
                    }
                }
            }
            return dist;
        };

        for (auto& edge : edges) {
            int u = edge[0], v = edge[1], w = edge[2];

            vector<int> dist = dijkstra(u, u, v);
            if (dist[v] < INF) {
                minCycle = min(minCycle, dist[v] + w);
            }
        }

        return (minCycle == INF) ? -1 : minCycle;
        
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;
        vector<vector<int>> edges;
        int i = 0;
        while (i++ < E) {
            int u, v, w;
            cin >> u >> v >> w;
            edges.push_back({u, v, w});
            edges.push_back({v, u, w});
        }

        Solution obj;
        int res = obj.findMinCycle(V, edges);

        cout << res << endl;
    }

    return 0;
}
// } Driver Code Ends