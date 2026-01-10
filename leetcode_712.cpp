class Solution {
public:
    int n,m;
    int dp[1001][1001];
    int f(int i,int j,string& s1,string&s2){
        if(i==n){
            int sum=0;
            for(int idx=j;idx<m;idx++) sum+=s2[idx];
            return sum;
        }
        if(j==m){
            int sum=0;
            for(int idx=i;idx<n;idx++) sum+=s1[idx];
            return sum;
        }
        if(dp[i][j]!=-1) return dp[i][j];
        int x=INT_MAX;
        int y=INT_MAX;
        int z=INT_MAX;
        if(s1[i]==s2[j]) x=f(i+1,j+1,s1,s2);
        else{
            y=int(s1[i])+f(i+1,j,s1,s2);
            z=int(s2[j])+f(i,j+1,s1,s2);
        }
        return dp[i][j]=min({x,y,z});
    }
    int minimumDeleteSum(string s1, string s2) {
        n=s1.size();
        m=s2.size();
        memset(dp,-1,sizeof(dp));
        return f(0,0,s1,s2);
    }
};