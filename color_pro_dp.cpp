class Solution {
public:
    int m=1e9+7;
    vector<string> ac;
    void f(string s,int l,char prev){
        if(l==3){
            ac.push_back(s);
            return;
        }
        for(auto ch:{'R','Y','G'}){
            if(ch==prev) continue;
            f(s+ch,l+1,ch);
        }
    }
    vector<vector<int>> dp;
    int solve(int curr,int rem){
        if(rem==0) return 1;
        if(dp[rem][curr]!=-1) return dp[rem][curr];
        int way=0;
        for(int i=0;i<ac.size();i++){
            if(curr==i) continue;
            if(ff(ac[i],ac[curr])) way=(way+solve(i,rem-1))%m;
        }
        return dp[rem][curr]=way;
    }
    bool ff(string curr,string prev){
        for(int i=0;i<curr.size();i++){
            if(curr[i]==prev[i]) return false;
        }
        return true;
    }
    int numOfWays(int n) {
        f("",0,'#');
        dp.resize(n+1,vector<int>(ac.size()+1,-1));
        long long int ans=0;
        for(int i=0;i<ac.size();i++){
            ans=(ans+solve(i,n-1))%m;
        }
        return ans;
    }
};