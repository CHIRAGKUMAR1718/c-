class Solution {
public:
    int n,m;
    int maxIncreaseKeepingSkyline(vector<vector<int>>& grid) {
        n=grid.size();
        m=grid[0].size();
        vector<int> r(n,0);
        vector<int> c(m,0);
        for(int i=0;i<n;i++){
            int maxi=INT_MIN;
            for(int j=0;j<m;j++){
                maxi=max(maxi,grid[i][j]);
            }
            r[i]=maxi;
        }
        for(int i=0;i<m;i++){
            int maxi=INT_MIN;
            for(int j=0;j<n;j++){
                maxi=max(maxi,grid[j][i]);
            }
            c[i]=maxi;
        }
        vector<vector<int>> ans(n,vector<int>(m,0));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                ans[i][j]=abs(grid[i][j]-min(r[i],c[j]));
            }
        }
        int sum=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                sum+=ans[i][j];
            }
        }
        return sum;
    }
};