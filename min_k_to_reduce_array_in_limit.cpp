class Solution {
public:
    int minimumK(vector<int>& nums) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        int target=nums[n-1];
        int low=1;
        int high=100000;
        int ans=0;
        while(low<=high){
            int mid=((high-low)/2)+low;
            unsigned long long int sum=0;
            for(int i=0;i<n;i++){
                sum+=(nums[i]/mid)+((nums[i]%mid==0)?0:1);
            }
            if(sqrt(sum)<=mid){
                ans=mid;
                high=mid-1;
            }else{
                low=mid+1;
            }
        }
        return ans;
    }
};