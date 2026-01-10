class Solution {
public:
    int n,m;
    int dp[501][501];
    int f(int i,int j,string&word1,string&word2){
        if(i==n){
            int sum=0;
            for(int idx=j;idx<m;idx++) sum+=1;
            return sum;
        }
        if(j==m){
            int sum=0;
            for(int idx=i;idx<n;idx++) sum+=1;
            return sum;
        }
        if(dp[i][j]!=-1) return dp[i][j];
        int x=INT_MAX;
        int y=INT_MAX;
        int z=INT_MAX;
        if(word1[i]==word2[j]) x=f(i+1,j+1,word1,word2);
        else{
            y=1+f(i+1,j,word1,word2);
            z=1+f(i,j+1,word1,word2);
        }
        return dp[i][j]=min({x,y,z});
    }
    int minDistance(string word1, string word2) {
        n=word1.size();
        m=word2.size();
        memset(dp,-1,sizeof(dp));
        return f(0,0,word1,word2);
    }
};