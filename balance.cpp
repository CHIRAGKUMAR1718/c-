class Solution {
public:
    int bs(int i,int j,int a,vector<int>&nums,int k){
        int x=i;
        int y=0;
        int n=nums.size();
        while(i<=j){
            int mid=i+(j-i)/2;
            if(nums[mid]<=(long long)k*a){
                y=mid;
                i=mid+1;
            }
            else j=mid-1;
        }
        return n-(y-x+1);
    }
    int minRemoval(vector<int>& nums, int k) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        int  ans=INT_MAX;
        for(int i=0;i<n;i++){
            int p=bs(i,n-1,nums[i],nums,k);
            ans=min(ans,p);
        }
        return ans;
    }
};