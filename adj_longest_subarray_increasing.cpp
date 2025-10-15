class Solution {
public:
    int maxIncreasingSubarrays(vector<int>& nums) {
        int n=nums.size();
        int prev=0;
        int curr=1;
        int maxi=1;
        int i=0;
        while(i<n-1){
            while(i<n-1 && nums[i]<nums[i+1]){
                curr++;
                maxi=max(maxi,curr/2);
                maxi=max(maxi,min(curr,prev));
                i++;
            }
            prev=curr;
            curr=1;
            i++;
        }
        return maxi;
    }
};