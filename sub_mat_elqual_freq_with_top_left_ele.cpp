class Solution {
public:
    int numberOfSubmatrices(vector<vector<char>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<pair<int,int>>> mat(n,vector<pair<int,int>>(m,{0,0}));
        for(int i=0;i<n;i++){
            if(grid[i][0]=='X') mat[i][0].first=1;
            if(grid[i][0]=='Y') mat[i][0].second=1;
        }
        for(int i=1;i<m;i++){
            for(int j=0;j<n;j++){
                mat[j][i]=mat[j][i-1];
                if(grid[j][i]=='X') mat[j][i].first+=1;
                if(grid[j][i]=='Y') mat[j][i].second+=1;
            }
        }
        int ans=0;
        for(int i=0;i<m;i++){
            int sumx=0;
            int sumy=0;
            for(int j=0;j<n;j++){
                sumx+=mat[j][i].first;
                sumy+=mat[j][i].second;
                if(sumx>0 && sumx==sumy) ans++;
            }
        }
        return ans;
    }
};