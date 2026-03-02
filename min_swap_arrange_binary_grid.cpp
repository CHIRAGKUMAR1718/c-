class Solution {
public:
    void f(int r,int c,int& ans,vector<vector<int>>& grid,int count){
        int n=grid.size();
        if(ans==-1) return;
        if(r>=n) return;   
        int cnt=0;
        for(int i=n-1;i>=0;i--){
            if(grid[r][i]==0) cnt++;
            else break;
        }
        if(cnt>=count){
            f(r+1,c+1,ans,grid,count-1);
        }
        else{
            int row=-1;
            for(int i=r+1;i<n;i++){
                int ct=0;
                for(int j=n-1;j>=0;j--){
                    if(grid[i][j]==0) ct++;
                    else break;
                }
                if(ct>=count){
                    row=i;
                    break;
                }
            }
            if(row==-1){
                ans=-1;
                return;
            }
            while(row>r){
                swap(grid[row], grid[row-1]);
                ans++;
                row--;
            }
            f(r+1,c+1,ans,grid,count-1);
        }
    }
    int minSwaps(vector<vector<int>>& grid) {
        int ans=0;
        int n=grid.size();
        f(0,1,ans,grid,n-1);
        return ans;
    }
};