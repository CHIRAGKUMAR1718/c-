class Solution {
public:
    long long countMajoritySubarrays(vector<int>& nums, int target) {
        long long ans=0;
        unordered_map<int,int> m;
        m[0]=1;
        int valid_left=0;
        int cum_sum=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==target){
                valid_left+=m[cum_sum];
                cum_sum++;
            }else{
                cum_sum--;
                valid_left-=m[cum_sum];
            }
            ans+=valid_left;
            m[cum_sum]++;
        }
        return ans;
    }
};