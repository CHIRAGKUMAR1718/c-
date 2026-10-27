class Solution {
public:
    int n,m;
    vector<vector<int>> dir={{1,0},{0,1},{-1,0},{0,-1}};
    void bfs(int sr,int sc,vector<vector<int>>& grid,long long& sum,vector<vector<int>>& visited){
        queue<pair<int,int>> q;
        q.push({sr,sc});
        visited[sr][sc]=1;
        while(!q.empty()){
            int size=q.size();
            while(size--){
                auto curr=q.front();
                q.pop();
                sum+=grid[curr.first][curr.second];
                for(int d=0;d<4;d++){
                    int nr=curr.first+dir[d][0];
                    int nc=curr.second+dir[d][1];
                    if(nr>=0 && nc>=0 && nr<n && nc<m && visited[nr][nc]==0 && grid[nr][nc]!=0){
                        visited[nr][nc]=1;
                        q.push({nr,nc});
                    }
                }
            }
        }
    }
    int countIslands(vector<vector<int>>& grid, int k) {
        n=grid.size();
        m=grid[0].size();
        vector<vector<int>> visited(n,vector<int>(m,0));
        vector<long long> ans;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==0 || visited[i][j]==1) continue;
                long long sum=0;
                bfs(i,j,grid,sum,visited);
                ans.push_back(sum);
            }
        }
        int count=0;
        for(auto i:ans) if(i%k==0) count++;
        return count;
    }
};