class Solution {
public:
    int minScore(int n, vector<vector<int>>& roads) {
        vector<vector<pair<int, int>>> adj(n + 1);
        for (const auto& road : roads) {
            int u = road[0], v = road[1], distance = road[2];
            adj[u].push_back({v, distance});
            adj[v].push_back({u, distance});
        }

        int minRoadScore = 1e9;
        vector<bool> visited(n + 1, false);
        queue<int> q;

        q.push(1);
        visited[1] = true;

        while (!q.empty()) {
            int u = q.front();
            q.pop();

            for (const auto& neighbor : adj[u]) {
                int v = neighbor.first;
                int distance = neighbor.second;
                
                minRoadScore = min(minRoadScore, distance);
                
                if (!visited[v]) {
                    visited[v] = true;
                    q.push(v);
                }
            }
        }

        return minRoadScore;
    }
};