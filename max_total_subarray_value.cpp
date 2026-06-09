class Solution {
public:
    long long maxTotalValue(vector<int>& nums, int k) {
        long long maxi=INT_MIN;
        long long mini=INT_MAX;
        for(auto i:nums){
            maxi=max(maxi,(long long)i);
            mini=min(mini,(long long)i);
        }
        return (maxi-mini)*k;
    }
};