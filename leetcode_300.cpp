class Solution {
public:
    int n;
    vector<vector<int>> dp;
    int f(int i,vector<int>&nums,int prev){
        if(i==n) return 0;
        if(dp[i][prev+1]!=-1) return dp[i][prev+1];
        int x=0;
        int y=0;
        if(prev==-1 || nums[i]>nums[prev]){
            x=1+f(i+1,nums,i);
        }
        y=f(i+1,nums,prev);
        return dp[i][prev+1]=max({x,y});
    }
    int lengthOfLIS(vector<int>& nums) {
        n=nums.size();
        dp.resize(n,vector<int>(n+1,-1));
        return f(0,nums,-1);
    }
};