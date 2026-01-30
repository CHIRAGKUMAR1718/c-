class Solution {
public:
    int dp[10001][101];
    int f(int egg,int floor){
        if(egg==1) return floor;
        if(floor==0 || floor==1) return floor;
        if(dp[floor][egg]!=-1) return dp[floor][egg];
        int ans=INT_MAX;
        int l=1;
        int h=floor;
        while(l<=h){
            int mid=(l+h)/2;
            int x=f(egg-1,mid-1);
            int y=f(egg,floor-mid);
            int x_y=1+max(x,y);
            if(y>x) l=mid+1;
            else h=mid-1;
            ans=min(ans,x_y);
        }
        return dp[floor][egg]=ans;
    }
    int superEggDrop(int k, int n) {
        memset(dp,-1,sizeof(dp));
        return f(k,n);
    }
};