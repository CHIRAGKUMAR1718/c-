class Solution {
public:
    int n;
    long long mod=1000000007;
    long long dp[202][202][202];
    int f(int idx,vector<int>& nums,int seq1,int seq2){
        if(idx==n) return (seq1==seq2 && seq1!=0) ? 1 : 0;
        if(dp[idx][seq1][seq2]!=-1) return dp[idx][seq1][seq2];
        long long ans=0;
        long long seq1_take=0;
        if(seq1==0) seq1_take=f(idx+1,nums,nums[idx],seq2);
        else seq1_take=f(idx+1,nums,gcd(nums[idx],seq1),seq2);
        ans=(ans+seq1_take)%mod;

        long long seq2_take=0;
        if(seq2==0) seq2_take=f(idx+1,nums,seq1,nums[idx]);
        else seq2_take=f(idx+1,nums,seq1,gcd(nums[idx],seq2));
        ans=(ans+seq2_take)%mod;
        
        long long skip=f(idx+1,nums,seq1,seq2);
        ans=(ans+skip)%mod;
        return dp[idx][seq1][seq2]=ans;
    }
    int subsequencePairCount(vector<int>& nums) {
        n=nums.size();
        memset(dp,-1,sizeof(dp));
        return f(0,nums,0,0);
    }
};