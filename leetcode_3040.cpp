class Solution {
public:
    int f(int i,int j,int sum,vector<vector<int>>& dp,vector<int>&nums){
        if(j-i+1<2) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        int ans=0;
        if(nums[i]+nums[i+1]==sum) ans=max(ans,1+f(i+2,j,sum,dp,nums));
        if(nums[i]+nums[j]==sum) ans=max(ans,1+f(i+1,j-1,sum,dp,nums));
        if(nums[j]+nums[j-1]==sum) ans=max(ans,1+f(i,j-2,sum,dp,nums));
        return dp[i][j]=ans;
    }
    int maxOperations(vector<int>& nums) {
        int n=nums.size();
        int sum1=nums[0]+nums[1];
        int sum2=nums[0]+nums[n-1];
        int sum3=nums[n-1]+nums[n-2];
        vector<vector<int>> dp1(n+1,vector<int>(n+1,-1));
        vector<vector<int>> dp2(n+1,vector<int>(n+1,-1));
        vector<vector<int>> dp3(n+1,vector<int>(n+1,-1));
        int x=f(0,n-1,sum1,dp1,nums);
        int y=f(0,n-1,sum2,dp2,nums);
        int z=f(0,n-1,sum3,dp3,nums);
        return max({x,y,z});
    }
};