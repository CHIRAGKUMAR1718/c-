class Solution {
public:
    int maxIceCream(vector<int>& nums, int coins) {
        int ans=0;
        sort(nums.begin(),nums.end());
        for(int i=0;i<nums.size();i++){
            if(coins<nums[i]) break;
            else{
                ans++;
                coins-=nums[i];
            }
        }
        return ans;
    }
};