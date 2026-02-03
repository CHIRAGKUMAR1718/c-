class Solution {
public:
    bool isTrionic(vector<int>& nums) {
        int p=-1;
        int n=nums.size();
        for(int i=0;i<n-1;i++){
            if(nums[i]>nums[i+1]){
                p=i;
                break;
            }
            if(nums[i]==nums[i+1]) return false;
        }
        if(p==-1) return false;
        int q=n;
        for(int i=p;i<n-1;i++){
            if(nums[i]<nums[i+1]){
                q=i;
                break;
            }
            if(nums[i]==nums[i+1]) return false;
        }
        for(int i=q+1;i<n-1;i++) if(nums[i]>=nums[i+1]) return false;
        return (0<p && p<q && q<n-1);
    }
};