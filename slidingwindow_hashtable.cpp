class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        int n=nums.size();
        int i=0;
        int j=0;
        int maxi=0;
        int sum=0;
        unordered_set<int>visited;
        while(j<n){
            while(visited.count(nums[j])){
                maxi=max(maxi,sum);
                sum-=nums[i];
                visited.erase(nums[i]);
                i++;
            }
            sum+=nums[j];
            visited.insert(nums[j]);
            j++;
        }
        maxi=max(maxi,sum);
        return maxi;
    }
};