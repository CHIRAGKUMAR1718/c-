class Solution {
public:
    vector<vector<int>> dir={{1,0},{0,1},{-1,0},{0,-1}};
    int n,m;
    vector<vector<int>> bfs(vector<vector<int>>& isWater,vector<vector<int>>& iswater){
        vector<vector<int>> visited(n,vector<int>(m,0));
        queue<pair<int,int>> q;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(isWater[i][j]==1){
                    q.push({i,j});
                    visited[i][j]=1;
                }
            }
        }
        while(!q.empty()){
            int size=q.size();
            while(size--){
                auto curr=q.front();
                q.pop();
                for(int d=0;d<4;d++){
                    int nr=curr.first+dir[d][0];
                    int nc=curr.second+dir[d][1];
                    if(nr>=0 && nc>=0 && nr<n && nc<m && visited[nr][nc]==0){
                        iswater[nr][nc]=iswater[curr.first][curr.second]+1;
                        q.push({nr,nc});
                        visited[nr][nc]=1;
                    }
                }
            }
        }
        return iswater;
    }

    vector<vector<int>> highestPeak(vector<vector<int>>& isWater) {
        n=isWater.size();
        m=isWater[0].size();
        vector<vector<int>> iswater(n,vector<int>(m,0));
        return bfs(isWater,iswater);
    }
};