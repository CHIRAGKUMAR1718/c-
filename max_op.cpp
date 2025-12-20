class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n=nums.size();
        unordered_map<int,int> m;
        for(auto i:nums) m[i]++;
        if(m.size()==n) return 0;
        int ans=0;
        int i=0;
        while(i<n){
            ans++;
            m[nums[i]]--;
            if(m[nums[i]]==0) m.erase(nums[i]);
            i++;
            if(i>=n) break;
             m[nums[i]]--;
            if(m[nums[i]]==0) m.erase(nums[i]);
            i++;
            if(i>=n) break;
             m[nums[i]]--;
            if(m[nums[i]]==0) m.erase(nums[i]);
            i++;
            if(m.size()==n-i) break;
        }
        return ans;
    }
};