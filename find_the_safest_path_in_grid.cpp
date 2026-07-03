class Solution {
public:
    vector<vector<int>> dir={{1,0},{0,1},{-1,0},{0,-1}};
    int n,m;
    void bfs1(vector<vector<int>>& grid,vector<vector<int>>& safe_mat){
        queue<pair<int,int>> q;
        set<pair<int,int>> visited;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1){
                    q.push({i,j});
                    visited.insert({i,j});
                }
            }
        }
        int count=1;
        while(!q.empty()){
            int size=q.size();
            while(size--){
                auto curr=q.front();
                q.pop();
                int sr=curr.first;
                int sc=curr.second;
                for(int d=0;d<4;d++){
                    int nr=sr+dir[d][0];
                    int nc=sc+dir[d][1];
                    if(nr>=0 && nc>=0 && nr<n && nc<m && !visited.count({nr,nc})){
                        safe_mat[nr][nc]=count;
                        q.push({nr,nc});
                        visited.insert({nr,nc});
                    }
                }
            }
            count++;
        }
    }

    bool check(vector<vector<int>>& mat,int target){
        vector<vector<bool>> visited(n,vector<bool>(m,false));
        queue<pair<int,int>> q;
        if(mat[0][0]<target) return false;
        q.push({0,0});
        visited[0][0]=true;
        while(!q.empty()){
            auto curr=q.front();
            q.pop();
            int sr=curr.first;
            int sc=curr.second;
            if(sr==n-1 && sc==m-1) return true;
            for(int d=0;d<4;d++){
                int nr=sr+dir[d][0];
                int nc=sc+dir[d][1];
                if(nr>=0 && nc>=0 && nr<n && nc<m && visited[nr][nc]==false){
                    if(mat[nr][nc]>=target){
                        q.push({nr,nc});
                        visited[nr][nc]=true;
                    }
                }
            }
        }
        return false;
    }

    int maximumSafenessFactor(vector<vector<int>>& grid) {
        n=grid.size();
        m=grid[0].size();
        vector<vector<int>> safe_mat(n,vector<int>(m,0));
        bfs1(grid,safe_mat);
        int ans=INT_MIN;
        int low=0;
        int high=500;
        while(low<=high){
            int mid=low+(high-low)/2;
            if(check(safe_mat,mid)){
                ans=max(ans,mid);
                low=mid+1;
            }else{
                high=mid-1;
            }
        }
        return ans;
    }
};