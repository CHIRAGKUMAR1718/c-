class Solution {
public:
    int mod = 1e9+7;
    int dp[201][201][2];
    int f(int zero,int one,int last,int limit){
        if(zero==0 && one==0) return 1;
        if(dp[zero][one][last]!=-1)
            return dp[zero][one][last];
        long long ans=0;
        if(last==1){
            for(int len=1; len<=min(zero,limit); len++){
                ans = (ans + f(zero-len, one, 0, limit)) % mod;
            }
        }
        else{ 
            for(int len=1; len<=min(one,limit); len++){
                ans = (ans + f(zero, one-len, 1, limit)) % mod;
            }
        }
        return dp[zero][one][last] = ans;
    }
    int numberOfStableArrays(int zero, int one, int limit) {
        memset(dp,-1,sizeof(dp));
        long long ans=0;
        ans = (ans + f(zero,one,0,limit)) % mod; 
        ans = (ans + f(zero,one,1,limit)) % mod; 
        return ans;
    }
};
