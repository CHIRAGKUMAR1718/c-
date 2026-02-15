class Solution {
public:
    int dp[1001][1001];
    vector<vector<int>> pref;
    int f(int i,int j,string& s){
        if(i==j) return 1;
        if(i>j) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        int val = -1;
        bool ok = true;
        for(int c=0;c<26;c++){
            int cnt = pref[j+1][c] - pref[i][c];
            if(cnt > 0){
                if(val == -1) val = cnt;
                else if(val != cnt){
                    ok = false;
                    break;
                }
            }
        }
        if(ok)
            return dp[i][j] = j - i + 1;
        int x = f(i+1,j,s);
        int y = f(i,j-1,s);
        return dp[i][j] = max(x,y);
    }
    int longestBalanced(string s) {
        int n = s.size();
        memset(dp,-1,sizeof(dp));
        pref.assign(n+1, vector<int>(26,0));
        for(int i=0;i<n;i++){
            pref[i+1] = pref[i];
            pref[i+1][s[i]-'a']++;
        }
        return f(0,n-1,s);
    }
};
