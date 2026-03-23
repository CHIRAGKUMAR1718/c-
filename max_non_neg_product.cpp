class Solution {
public:
    int n,m;
    using ll=long long;
    vector<vector<int>> dir={{0,1},{1,0}};
    unordered_map<string,pair<ll,ll>> dp;
    pair<ll,ll> f(int sr,int sc,vector<vector<int>>& grid){
        if(sr==n-1 && sc==m-1) return {grid[sr][sc],grid[sr][sc]};
        string key=to_string(sr)+" "+to_string(sc);
        if(dp.count(key)) return dp[key];
        ll curr_max=LLONG_MIN;
        ll curr_min=LLONG_MAX;
        for(int d=0;d<2;d++){
            int nr=sr+dir[d][0];
            int nc=sc+dir[d][1];
            if(nr>=0 && nc>=0 && nr<n && nc<m){
                auto[a,b]=f(nr,nc,grid);
                ll g = grid[sr][sc];
                curr_max=max({curr_max,a*g,b*g});
                curr_min=min({curr_min,a*g,b*g});
            }
        }
        return dp[key]={curr_max,curr_min};
    }
    int maxProductPath(vector<vector<int>>& grid) {
        n=grid.size();
        m=grid[0].size();
        auto [a,b]=f(0,0,grid);
        if(a<0) return -1;
        return a%(int)(1e9+7);
    }
};