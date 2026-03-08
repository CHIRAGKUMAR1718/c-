class Solution {
public:
    int largestSubmatrix(vector<vector<int>>& mat) {
        int n=mat.size();
        int m=mat[0].size();
        vector<vector<int>> nums(n,vector<int>(m,0));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(mat[i][j]==0) nums[i][j]=0;
                else{
                    if(i-1>=0) nums[i][j]=nums[i-1][j]+1;
                    else nums[i][j]=1;
                }
            }
        }
        int ans=0;
        for(auto i:nums){
            vector<int> v=i;
            sort(v.begin(),v.end());
            for(int i=0;i<v.size();i++){
                int x=v[i]*(v.size()-i);
                ans=max(ans,x);
            }
        }
        return ans;
    }
};