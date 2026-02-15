class Solution {
public:
    long long putMarbles(vector<int>& nums, int k) {
        int n=nums.size();
        if(n==1) return 0;
        priority_queue<long long> maxi;
        priority_queue<long long,vector<long long>,greater<long long>> mini;
        for(int i=1;i<n;i++){
            long long p=nums[i]+nums[i-1];
            maxi.push(p);
            mini.push(p);
        }
        long long ma=nums[0]+nums[n-1];
        long long mi=nums[0]+nums[n-1];
        int x=k;
        while(x!=1){
            ma+=maxi.top();
            maxi.pop();
            x--;
        }
        x=k;
        while(x!=1){
            mi+=mini.top();
            mini.pop();
            x--;
        }
        return ma-mi;
    }
};