class Solution {
public:
    int n;


    int f(int sr,vector<int>&arr,int d,vector<int>&dp){
        int ans=1;
        if(dp[sr]!=-1) return dp[sr];
        for(int i=sr+1;i<=min(sr+d,n-1);i++){
            if(arr[i]<arr[sr]) ans=max(ans,1+f(i,arr,d,dp));
            else break;
        }
        for(int i=sr-1;i>=max(0,sr-d);i--){
            if(arr[i]<arr[sr]) ans=max(ans,1+f(i,arr,d,dp));
            else break; 
        }
        return dp[sr]=ans;
    }


    int maxJumps(vector<int>& arr, int d) {
        n=arr.size();
        int ans=INT_MIN;
        for(int i=0;i<n;i++){
            vector<int> dp(n+1,-1);
            int x=f(i,arr,d,dp);
            ans=max(ans,x);
        }
        return ans;
    }
};