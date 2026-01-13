class Solution {
public:
    int n;
    int dp[501];
    int f(int idx,vector<int>&nums,int k){
        if(idx==n) return 0;
        if(dp[idx]!=-1) return dp[idx];
        int ans=0;
        int maxi=0;
        for(int i=idx;i<n && i-idx+1<=k;i++){
            maxi=max(maxi,nums[i]);
            ans=max(ans,(i-idx+1)*maxi+f(i+1,nums,k));
        }
        return dp[idx]=ans;
    }
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        n=arr.size();
        memset(dp,-1,sizeof(dp));
        return f(0,arr,k);
    }
};