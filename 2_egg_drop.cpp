class Solution {
public:
    int dp[1001][3];
    int f(int floor,int egg){
        if(egg==1) return floor;
        if(floor==0 || floor==1) return floor;
        if(dp[floor][egg]!=-1) return dp[floor][egg];
        int ans=INT_MAX;
        for(int i=1;i<=floor;i++){
            int x=f(i-1,egg-1);
            int y=f(floor-i,egg);
            ans=min(ans,1+max(x,y));
        }
        return dp[floor][egg]=ans;
    }
    int twoEggDrop(int n) {
        memset(dp,-1,sizeof(dp));
        return f(n,2);
    }
};