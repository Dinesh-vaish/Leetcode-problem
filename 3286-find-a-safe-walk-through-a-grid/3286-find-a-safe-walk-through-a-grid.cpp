class Solution {
public:
    bool findSafeWalk(vector<vector<int>>& grid, int health) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> dist(m, vector<int>(n, INT_MAX));
        
        using T = pair<int, pair<int,int>>; // {cost, {x,y}}
        priority_queue<T, vector<T>, greater<T>> pq;
        
        dist[0][0] = grid[0][0];
        pq.push({dist[0][0], {0,0}});
        
        vector<int> dx = {1,-1,0,0};
        vector<int> dy = {0,0,1,-1};
        
        while(!pq.empty()){
            auto [cost, pos] = pq.top(); pq.pop();
            int x = pos.first, y = pos.second;
            
            if(x == m-1 && y == n-1){
                return cost < health; 
            }
            
            for(int k=0;k<4;k++){
                int nx = x + dx[k], ny = y + dy[k];
                if(nx>=0 && ny>=0 && nx<m && ny<n){
                    int newCost = cost + grid[nx][ny];
                    if(newCost < dist[nx][ny]){
                        dist[nx][ny] = newCost;
                        pq.push({newCost, {nx,ny}});
                    }
                }
            }
        }
        return false;
    }
};
