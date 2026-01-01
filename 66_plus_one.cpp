class Solution {
public:
    vector<int> plusOne(vector<int>& nums) {
        int n=nums.size();
        int idx=0;
        if(nums[n-1]!=9){
            nums[n-1]+=1;
            return nums;
        }
        else{
            for(int i=n-1;i>=0;i--){
                if(nums[i]==9) nums[i]=0;
                else{
                    idx=i;
                    break;
                }
            }
        }
        if(nums[0]!=0){
            nums[idx]+=1;
            return nums;
        }
        vector<int> ans(n+1,0);
        ans[0]=1;
        return ans;
    }
};