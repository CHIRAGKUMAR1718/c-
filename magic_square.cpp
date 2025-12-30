class Solution {
public:
    int n,m;
    bool f(int col,int row,vector<vector<int>>& grid){
        int sc=col-2;
        int ec=col;
        int sr=row;
        int er=row+2;
        set<int> s;
        for(int i=sr;i<=er;i++){
            for(int j=sc;j<=ec;j++){
                s.insert(grid[i][j]);
            }
        }
        if(s.size()!=9 || *s.rbegin()!=9) return false;
        int r1=grid[sr][sc]+grid[sr][sc+1]+grid[sr][sc+2];
        int r2=grid[sr+1][sc]+grid[sr+1][sc+1]+grid[sr+1][sc+2];
        int r3=grid[sr+2][sc]+grid[sr+2][sc+1]+grid[sr+2][sc+2];
        int c1=grid[sr][sc]+grid[sr+1][sc]+grid[sr+2][sc];
        int c2=grid[sr][sc+1]+grid[sr+1][sc+1]+grid[sr+2][sc+1];
        int c3=grid[sr][sc+2]+grid[sr+1][sc+2]+grid[sr+2][sc+2];
        int d1=grid[sr][sc]+grid[sr+1][sc+1]+grid[sr+2][sc+2];
        int d2=grid[sr][sc+2]+grid[sr+1][sc+1]+grid[sr+2][sc];
        set<int> ss={r1,r2,r3,c1,c2,c3,d1,d2};
        if(ss.size()==1) return true;
        return false;
        
    }
    int numMagicSquaresInside(vector<vector<int>>& grid) {
        n=grid.size();
        m=grid[0].size();
        int ans=0;
        for(int col=2;col<m;col++){
            for(int row=0;row<n-2;row++){
                if(f(col,row,grid)) ans++;
            }
        }
        return ans;
    }
};