class Solution {
public:
    int sortPermutation(vector<int>& nums) {
        vector<int> v;
        int n=nums.size();
        for(int i=0;i<n;i++){
            if(nums[i]!=i) v.push_back(nums[i]);
        }
        int ans=INT_MAX;
        for(auto i:v) ans&=i;
        return (ans==INT_MAX)?0:ans;
    }
};