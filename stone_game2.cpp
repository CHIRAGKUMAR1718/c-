class Solution {
public:
    int dp[105][105][2];
    int f(vector<int>&nums,int m,int idx,bool flag){
        if(idx>=nums.size()) return 0;
        if(dp[m][idx][flag]!=-1) return dp[m][idx][flag];
        if(flag){
            int ans=0;
            int sum=0;
             for (int i = idx; i < nums.size() && i < idx + 2 * m; i++) {
                sum += nums[i];
                int mx = max(m, i + 1 - idx);
                ans = max(ans, sum + f(nums, mx, i + 1, false));
            }
            return dp[m][idx][flag]=ans;
        }else{
            int ans = INT_MAX;
            for (int i = idx; i < nums.size() && i < idx + 2 * m; i++) {
                int mx = max(m, i + 1 - idx);
                ans = min(ans, f(nums, mx, i + 1, true));
            }
            return dp[m][idx][flag]=ans;
        }
    }
    int stoneGameII(vector<int>& nums) {
        memset(dp,-1,sizeof(dp));
        return f(nums,1,0,true);
    }
};