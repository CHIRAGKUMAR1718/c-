class Solution {
public:
    vector<vector<int>> dir={{0,1},{1,0},{0,-1},{-1,0}};
    vector<vector<int>> colorGrid(int n, int m, vector<vector<int>>& sources) {
        queue<pair<int,int>> q;
        vector<vector<int>> ans(n,vector<int>(m,0));
        vector<vector<int>> dist(n,vector<int>(m,-1));
        for(int i=0;i<sources.size();i++){
            int r=sources[i][0];
            int c=sources[i][1];
            int col=sources[i][2];
            q.push({r,c});
            ans[r][c]=col;
            dist[r][c]=0;
        }
        while(q.size()!=0){
            auto curr=q.front();
            q.pop();
            int r=curr.first;
            int c=curr.second;
            for(int d=0;d<4;d++){
                int nr=r+dir[d][0];
                int nc=c+dir[d][1];
                if(nr>=0 && nc>=0 && nr<n && nc<m){
                    if(dist[nr][nc]==-1){
                        ans[nr][nc]=ans[r][c];
                        q.push({nr,nc});
                        dist[nr][nc]=dist[r][c]+1;
                    }
                    else if(dist[nr][nc]==dist[r][c]+1){
                        ans[nr][nc]=max(ans[nr][nc],ans[r][c]);
                    }
                }
            }
        }
        return ans;
    }
};