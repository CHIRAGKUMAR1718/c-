class Solution {
public:
    int n,m;
    int f(int curr,int prev,vector<string>& strs,vector<vector<int>>&dp){
        if(curr==n) return 0;
        if(dp[curr][prev+1]!=-1) return dp[curr][prev+1];
        int skip=f(curr+1,prev,strs,dp);
        int pick=0;
        if(prev==-1) pick=1+f(curr+1,curr,strs,dp);
        else{
            bool flag=true;
            for(int i=0;i<m;i++){
                if(strs[i][curr]<strs[i][prev]){
                    flag=false;
                    break;
                }
            }
            if(flag) pick=1+f(curr+1,curr,strs,dp);
        }
        return dp[curr][prev+1]=max(pick,skip);
    }
    int minDeletionSize(vector<string>& strs) {
        n=strs[0].size();
        m=strs.size();
        vector<vector<int>> dp(n,vector<int>(n+1,-1));
        return n-f(0,-1,strs,dp);
    }
};