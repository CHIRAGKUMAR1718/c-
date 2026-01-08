class Solution {
public:
    int n,m;
    int f(int i,int j,vector<int>&nums1,vector<int>&nums2,vector<vector<int>>&dp){
        if(i==n || j==m) return INT_MIN;
        if(dp[i][j]!=INT_MIN) return dp[i][j];
        int val=nums1[i]*nums2[j];
        int next = f(i + 1, j + 1, nums1, nums2, dp);
        int take = val;
        if (next != INT_MIN) {
            take = val + next;
        }
        int sk1=f(i+1,j,nums1,nums2,dp);
        int sk2=f(i,j+1,nums1,nums2,dp);
        return dp[i][j]=max({val,take,sk1,sk2});
    }
    int maxDotProduct(vector<int>& nums1, vector<int>& nums2) {
        n=nums1.size();
        m=nums2.size();
        vector<vector<int>> dp(n+1,vector<int>(m+1,INT_MIN));
        return f(0,0,nums1,nums2,dp);
    }
};