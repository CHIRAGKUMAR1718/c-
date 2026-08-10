class Solution {
public:
    vector<int> dp;
    void f(){
        for(int i=2;i<dp.size();i++){
            bool flag=false;
            for(int j=1;j<=sqrt(i);j++){
                if(dp[i-j*j]==0){
                    flag=true;
                    break;
                }
            }
            if(flag) dp[i]=1;
            else dp[i]=0;
        }
    }
    bool winnerSquareGame(int n) {
        dp.resize(n+1);
        dp[0]=0;
        dp[1]=1;
        f();
        return dp[n];
    }
};