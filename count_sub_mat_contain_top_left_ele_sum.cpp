class Solution {
public:
    int countSubmatrices(vector<vector<int>>& grid, int k) {
        int n=grid.size();
        int m=grid[0].size();
        for(int i=0;i<n;i++){
            for(int j=1;j<m;j++){
                grid[i][j]=grid[i][j-1]+grid[i][j];
            }
        }
        int ans=0;
        for(int i=0;i<m;i++){
            int sum=0;
            for(int j=0;j<n;j++){
                sum+=grid[j][i];
                if(sum<=k) ans++;
            }
        }
        return ans;
    }
};