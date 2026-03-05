class Solution {
public:
    long long minimumDifference(vector<int>& nums) {
        priority_queue<int> maxi;
        priority_queue<int,vector<int>,greater<int>> mini;
        int n=nums.size();
        vector<long long> pre(n);
        vector<long long> suf(n);
        pre[0]=nums[0];
        maxi.push(nums[0]);
        for(int i=1;i<n-n/3;i++){
            pre[i]=pre[i-1]+nums[i];
            maxi.push(nums[i]);
            if(maxi.size()>n/3){
                pre[i]-=maxi.top();
                maxi.pop();
            }
        }
        suf[n-1]=nums[n-1];
        mini.push(nums[n-1]);
        for(int i=n-2;i>=n/3;i--){
            suf[i]=suf[i+1]+nums[i];
            mini.push(nums[i]);
            if(mini.size()>n/3){
                suf[i]-=mini.top();
                mini.pop();
            }
        }
        long long ans=LLONG_MAX;
        for(int i=n/3-1;i<2*n/3;i++){
            long long x=pre[i]-suf[i+1];
            ans=min(ans,x);
        }
        return ans;
    }
};