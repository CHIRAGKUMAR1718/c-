class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n=nums.size();
        for(int i=0;i<n;i++) if(nums[i]<=0) nums[i]=n+3;
        for(int i=0;i<n;i++){
            int idx=abs(nums[i])-1;
            if(idx<0 || idx>=n) continue;
            else nums[idx]=(nums[idx]>0)?-nums[idx]:nums[idx];
        }
        for(int i=1;i<=n;i++){
            int idx=i-1;
            if(nums[idx]>0) return i;
        }
        return n+1;
    }
};