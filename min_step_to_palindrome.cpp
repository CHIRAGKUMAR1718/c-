class Solution {
public:
    int dp[502][502];
    int f(int i,int j,string& s){
        if(i==j || i>j) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        if(s[i]==s[j]) return dp[i][j]=f(i+1,j-1,s);
        int x=1+f(i+1,j,s);
        int y=1+f(i,j-1,s);
        return dp[i][j]=min(x,y);
    }
    int minInsertions(string s) {
        // hello 
        int n=s.size();
        memset(dp,-1,sizeof(dp));
        return f(0,n-1,s);
    }
};