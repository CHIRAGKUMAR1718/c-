class Solution {
public:
    int maximumElementAfterDecrementingAndRearranging(vector<int>& nums) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        nums[0]=1;
        for(int i=1;i<n;i++){
            if(abs(nums[i]-nums[i-1])>1) nums[i]=nums[i-1]+1;
        }
        int maxi=0;
        for(auto i:nums) maxi=max(maxi,i);
        return maxi;
    }
};