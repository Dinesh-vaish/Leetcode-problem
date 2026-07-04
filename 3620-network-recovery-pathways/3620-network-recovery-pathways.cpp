class Solution {
public:
    int findMaxPathScore(vector<vector<int>>& edges, vector<bool>& online, long long k) {
        int n = online.size();
        vector<vector<pair<int, int>>> adj(n);
        vector<int> inDegree(n, 0);
        
        for (const auto& edge : edges) {
            int u = edge[0], v = edge[1], cost = edge[2];
            adj[u].push_back({v, cost});
            inDegree[v]++;
        }

        queue<int> q;
        for (int i = 0; i < n; ++i) {
            if (inDegree[i] == 0) q.push(i);
        }

        vector<int> topoOrder;
        while (!q.empty()) {
            int u = q.front();
            q.pop();
            topoOrder.push_back(u);
            for (const auto& edge : adj[u]) {
                int v = edge.first;
                if (--inDegree[v] == 0) q.push(v);
            }
        }

        auto check = [&](int X) {
            vector<long long> dist(n, 1e18);
            dist[0] = 0;

            for (int u : topoOrder) {
                if (dist[u] == 1e18) continue;
                if (u != 0 && !online[u]) continue; 

                for (const auto& edge : adj[u]) {
                    int v = edge.first;
                    int cost = edge.second;
                    if (cost >= X) {
                        dist[v] = min(dist[v], dist[u] + cost);
                    }
                }
            }
            return dist[n - 1] <= k;
        };

        int low = 0, high = 1e9, ans = -1;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (check(mid)) {
                ans = mid;
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }

        return ans;
    }
};