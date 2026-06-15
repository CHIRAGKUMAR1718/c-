class Solution {
public:
    int n,m;
    int numSubmat(vector<vector<int>>& mat) {
        n=mat.size();
        m=mat[0].size();
        int ans=0;
        for(int sr=0;sr<n;sr++){
            vector<int> nums(m,1);
            for(int er=sr;er<n;er++){
                for(int j=0;j<m;j++){
                    nums[j]&=mat[er][j];
                }
                vector<int> res=nums;
                for(int k=1;k<m;k++){
                    if(res[k]==1) res[k]=res[k-1]+1; 
                }
                for(auto ele:res) ans+=ele;
            }
        }
        return ans;
    }
};