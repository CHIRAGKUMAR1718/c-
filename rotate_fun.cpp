class Solution {
public:
    int maxRotateFunction(vector<int>& nums) {
        int n=nums.size();
        int sum=0;
        for(auto i:nums) sum+=i;
        int prev=0;
        for(int i=0;i<n;i++) prev+=i*nums[i];
        int ans=prev;
        for(int i=1;i<n;i++){
            int next=prev+sum-(n*nums[n-i]);
            prev=next;
            ans=max(ans,next);
        }
        return ans;
    }
};