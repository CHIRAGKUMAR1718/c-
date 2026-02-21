class Solution {
public:
    int firstUniqueFreq(vector<int>& nums) {
        unordered_map<int,int> m;
        for(auto i:nums) m[i]++;
        unordered_map<int,int> freq;
        for(auto i:m) freq[i.second]++;
        for(int i=0;i<nums.size();i++){
            if(freq[m[nums[i]]]==1) return nums[i];
        }
        return -1;
    }
};