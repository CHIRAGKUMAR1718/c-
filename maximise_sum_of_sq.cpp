class Solution {
public:
    int maxSum(vector<int>& nums, int k) {
        int n=nums.size();
        vector<int> v(32,0);
        for(int i=0;i<n;i++){  
            for(int b=0;b<32;b++){
                if(nums[i] & 1<<b) v[b]++;
            }
        }
        long long ans=0;
        while(k--){
            long long curr=0;
            for(int b=0;b<32;b++){
                if(v[b]>0){
                    curr=curr|(1<<b);
                    v[b]--;
                }
            }
            curr=curr*curr;
            ans=(ans+curr)%1000000007;
        }
        return ans;
    }
};