class Solution {
public:

    int countIslands(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<int>> vis(m, vector<int>(n, 0));
        int count = 0;

        int dr[] = {-1, 1, 0, 0};
        int dc[] = {0, 0, -1, 1};

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {

                if (grid[i][j] == 1 && !vis[i][j]) {

                    count++;

                    queue<pair<int,int>> q;
                    q.push({i, j});
                    vis[i][j] = 1;

                    while (!q.empty()) {
                        auto [r, c] = q.front();
                        q.pop();

                        for (int k = 0; k < 4; k++) {
                            int nr = r + dr[k];
                            int nc = c + dc[k];

                            if (nr >= 0 && nr < m &&
                                nc >= 0 && nc < n &&
                                grid[nr][nc] == 1 &&
                                !vis[nr][nc]) {

                                vis[nr][nc] = 1;
                                q.push({nr, nc});
                            }
                        }
                    }
                }
            }
        }

        return count;
    }

    int minDays(vector<vector<int>>& grid) {

        // Already disconnected
        if (countIslands(grid) != 1)
            return 0;

        int m = grid.size();
        int n = grid[0].size();

        // Remove one land cell
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {

                if (grid[i][j] == 1) {

                    grid[i][j] = 0;

                    if (countIslands(grid) != 1)
                        return 1;

                    grid[i][j] = 1;
                }
            }
        }

        // Two cells are always enough
        return 2;
    }
};