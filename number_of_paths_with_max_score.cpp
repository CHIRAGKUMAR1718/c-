class Solution {
public:
    int dp_sum[105][105];
    int dp_count[105][105];
    int n;
    int mod=1000000007;
    vector<int> f(int sr,int sc,vector<string>& board){
        if(sr<0 || sc<0) return {-1,0};
        if(board[sr][sc]=='X') return {-1,0};
        if(board[sr][sc]=='E') return {0,1};
        if(dp_sum[sr][sc]!=-2) return {dp_sum[sr][sc],dp_count[sr][sc]};
        auto v1=f(sr-1,sc,board);
        auto v2=f(sr,sc-1,board);
        auto v3=f(sr-1,sc-1,board);
        long long path=0;
        int maxi=max({v1[0],v2[0],v3[0]});
        if(maxi==-1){
            dp_sum[sr][sc]=-1;
            dp_count[sr][sc]=0;
            return {-1,0};
        }
        if(v1[0]==maxi) path=(path+v1[1])%mod;;
        if(v2[0]==maxi) path=(path+v2[1])%mod;
        if(v3[0]==maxi) path=(path+v3[1])%mod;
        dp_count[sr][sc]=path;
        int val=(board[sr][sc]=='S')?0:(board[sr][sc]-'0');
        dp_sum[sr][sc]=maxi+val;
        return {dp_sum[sr][sc],dp_count[sr][sc]};
    }
    vector<int> pathsWithMaxScore(vector<string>& board) {
        n=board.size();
        for(int i=0;i<105;i++){
            for(int j=0;j<105;j++){
                dp_sum[i][j]=-2;
                dp_count[i][j]=-2;
            }
        }
        auto ans=f(n-1,n-1,board);
        if(ans[0]==-1) ans[0]=0;
        return ans;
    }
};