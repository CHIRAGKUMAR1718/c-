class Solution {
public:
    #define mod 1000000007
    long long power(int base, int exp) {
        long long res = 1;
        while (exp--) res *= base;
        return res;
    }
    int f(int n,int x,int idx,vector<vector<int>>& dp){
        if(n==0) return 1;
        if(n<0) return 0;
        if(dp[n][idx]!=-1) return dp[n][idx];
        long long ans=0;
        for(int i=idx;;i++){
            int p=power(i,x);
            if(p>n) break;
            ans+=f(n-p,x,i+1,dp);
            ans%=mod;
        }
        return dp[n][idx]=(int)ans;
    }
    int numberOfWays(int n, int x) {
        vector<vector<int>> dp(n+2,vector<int>(n+2,-1));
        return f(n,x,1,dp);
    }
};