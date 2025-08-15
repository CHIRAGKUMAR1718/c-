class Solution {
public:
    int m= 1e9+7;
    vector<string> ac;
    void f(string s,int l,int m,char prev){
        if(l==m){
            ac.push_back(s);
            return;
        }
        for(auto ch:{'R','G','B'}){
            if(ch==prev) continue;
            f(s+ch,l+1,m,ch);
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
    bool ff(string prev,string curr){
        for(int i=0;i<prev.size();i++){
            if(prev[i]==curr[i]) return false;
        }
        return true;
    }
    int colorTheGrid(int m, int n) {
        f("",0,m,'#');
        dp.resize(n+1,vector<int>(ac.size()+1,-1));
        long long ans=0;
        for(int i=0;i<ac.size();i++){
            ans=(ans+solve(i,n-1))%this->m;
        }
        return ans;
    }
};