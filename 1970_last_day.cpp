class Solution {
public:
    vector<vector<int>> dir={{0,1},{0,-1},{1,0},{-1,0}};
    int n,m;
    bool f(int sr,int sc,vector<vector<int>>& visited,vector<vector<int>>& grid){
        if(sr==n-1) return true;
        visited[sr][sc]=1;
        for(int d=0;d<4;d++){
            int nr=sr+dir[d][0];
            int nc=sc+dir[d][1];
            if(nr>=0 && nc>=0 && nr<n && nc<m && visited[nr][nc]==0 && grid[nr][nc]==0){
                if(f(nr,nc,visited,grid)) return true;
            }
        }
        return false;
    }
    int latestDayToCross(int row, int col, vector<vector<int>>& cells) {
        n=row;
        m=col;
        int ans=0;
        int lo=0;
        int hi=cells.size()-1;
        while(lo<=hi){
            int mid=(lo+hi)/2;
            vector<vector<int>> grid(n,vector<int>(m,0));
            vector<vector<int>> visited(n,vector<int>(m,0));
            for(int i=0;i<=mid;i++) grid[cells[i][0]-1][cells[i][1]-1]=1;
            bool flag=false;
            for(int i=0;i<col;i++){
                if(grid[0][i]==1) continue;
                if(f(0,i,visited,grid)){
                    flag=true;
                    break;
                }
            }
            if(flag){
                ans=mid+1;
                lo=mid+1;
            }
            else hi=mid-1;
        }
        return ans;
    }
};