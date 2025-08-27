class Solution {
public:
    vector<vector<int>> dir={{-1,-1},{-1,1},{1,1},{1,-1}};
    int n,m;
    int ff(int target){
        if(target==2) return 0;
        return 2;
    }
    int fff(int sr,int sc){
        int idx=0;
        for(int d=0;d<4;d++){
            if(dir[d][0]==sr && dir[d][1]==sc) idx=d;
        }
        return (idx==3)?0:idx+1;
    }

    int f(int sr,int sc,vector<vector<int>>& grid,int chance,int rd,int cd,int target){
        if(sr<0 || sc<0 || sr>=n || sc>=m) return 0;
        if(grid[sr][sc]!=target) return 0;
        int a=1+f(sr+rd,sc+cd,grid,chance,rd,cd,ff(target));
        int b=0;
        if(chance!=0){
            int curr=fff(rd,cd);
            rd=dir[curr][0];
            cd=dir[curr][1];
            b=1+f(sr+rd,sc+cd,grid,0,rd,cd,ff(target));
        }
        return max(a,b);
    }

    int lenOfVDiagonal(vector<vector<int>>& grid) {
        n=grid.size();
        m=grid[0].size();
        int ans=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1){
                    for(int d=0;d<4;d++){
                        int p=1;
                        int nr=i+dir[d][0];
                        int nc=j+dir[d][1];
                        if(nr>=0 && nc>=0 && nr<n && nc<m && grid[nr][nc]==2){
                            p+=f(nr,nc,grid,1,dir[d][0],dir[d][1],2);
                        }
                        ans=max(ans,p);
                    }
                }
            }
        }
        return ans;
    }
};