class Solution {
public:
    int dp[50005][2];
    int f(vector<int>&nums,int idx,bool flag){
        if(idx>=nums.size()) return 0;
        if(dp[idx][flag]!=-1) return dp[idx][flag];
        int a=INT_MIN;
        if(flag){
            int sum=0;
            for(int i=idx;i<nums.size() && i<idx+3;i++){
                sum+=nums[i];
                a=max(a,sum+f(nums,i+1,false));
            }
        }else{
            a=INT_MAX;
            int sum=0;
            for(int i=idx;i<nums.size() && i<idx+3;i++){
                sum+=nums[i];
                a=min(a,-sum+f(nums,i+1,true));
            }
        }
        return dp[idx][flag]=a;
    }
    string stoneGameIII(vector<int>& nums) {
        memset(dp,-1,sizeof(dp));
        int x=f(nums,0,true);
        if(x==0) return "Tie";
        if(x>0) return "Alice";
        return "Bob";
    }
};