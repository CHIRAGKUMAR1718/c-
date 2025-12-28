class Solution {
public:
    int f(int st,int en,vector<vector<int>>& grid){
        int lo=0;
        int hi=en-1;
        int ans=en;
        while(lo<=hi){
            int mid=(lo+hi)/2;
            if(grid[st][mid]<0){
                ans=mid;
                hi=mid-1;
            }
            else lo=mid+1;
        }
        cout<<en-ans<<endl;
        return en-ans;
    }
    int countNegatives(vector<vector<int>>& grid) {
        int row=grid.size();
        int col=grid[0].size();
        int ans=0;
        for(int i=0;i<row;i++){
            ans+=f(i,col,grid);
        }
        return ans;
    }
};