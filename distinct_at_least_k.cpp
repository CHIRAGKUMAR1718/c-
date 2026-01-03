class Solution {
public:
    int minLength(vector<int>& nums, int k) {
        int n=nums.size();
        int sum=0;
        int mini=INT_MAX;
        int i=0;
        int j=0;
        unordered_map<int,int> m;
        while(i<n && j<n){
            if(m[nums[j]]==0) sum+=nums[j];
            m[nums[j]]++;
            while(i<n && sum>=k){
                mini=min(mini,j-i+1);
                m[nums[i]]--;
                if(m[nums[i]] == 0) sum -= nums[i];
                i++;
            }
            j++;
        }
        if(mini==INT_MAX) return -1;
        return mini;
    }
};©leetcode