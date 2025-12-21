class Solution {
public:
    int minDeletionSize(vector<string>& nums) {
        int n=nums.size();
        int ans=0;
        vector<bool> als(n,false);
        for(int i=0;i<nums[0].size();i++){
            bool flag=false;
            for(int j=0;j<n-1;j++){
                if(!als[j] && nums[j][i]>nums[j+1][i]){
                    flag=true;
                    ans++;
                    break;
                }
            }
            if(flag) continue;
            for(int k=0;k<n-1;k++){
                als[k]=(als[k] | (nums[k][i] < nums[k+1][i]));
                
            }
        }
        return ans;
    }
};