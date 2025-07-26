class Solution {
public:

    bool f(int mid,vector<int>&nums,int m){
        int count=1;
        int prevpos=nums[0];
        for(int i=0;i<nums.size();i++){
            if(nums[i]-prevpos>=mid){
                count++;
                prevpos=nums[i];
            }
            if(count>=m) return true;
        }
        return false;
    }

    int maxDistance(vector<int>& nums, int m) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        int first=1;
        int last=nums[n-1]-nums[0];
        int ans=INT_MIN;
        while(last>=first){
            int mid=first+(last-first)/2;
            if(f(mid,nums,m)){
                ans=max(ans,mid);
                first=mid+1;
            }
            else last=mid-1;
        }
        return ans;
    }
};