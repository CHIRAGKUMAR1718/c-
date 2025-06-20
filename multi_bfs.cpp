class Solution {
public:
    vector<vector<int>> dir = {{1,0},{-1,0},{0,1},{0,-1}};
    int n, m;

    int bfs(vector<vector<int>>& grid){
        vector<vector<int>> visited(n, vector<int>(m, -1)); 
        queue<pair<int, int>> q;

        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(grid[i][j] == 1){
                    q.push({i,j});
                    visited[i][j] = 0; 
                }
            }
        }

        int maxDist = -1;
        while(!q.empty()){
            auto [i, j] = q.front(); q.pop();

            for(int d=0; d<4; d++){
                int ni = i + dir[d][0];
                int nj = j + dir[d][1];

                if(ni >= 0 && nj >= 0 && ni < n && nj < m && visited[ni][nj] == -1){
                    visited[ni][nj] = visited[i][j] + 1;
                    maxDist = max(maxDist, visited[ni][nj]);
                    q.push({ni, nj});
                }
            }
        }

        return maxDist;
    }

    int maxDistance(vector<vector<int>>& grid) {
        n = grid.size();
        m = grid[0].size();
        return bfs(grid);
    }
};
