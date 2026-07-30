class Solution {
public:
    using pp=pair<int,int>;
    long long maximumValueSum(vector<int>& nums, int k, vector<vector<int>>& edges) {
        long long ans=0;
        int n=nums.size();
        int mini=INT_MAX;
        priority_queue<pp> pq;
        for(int i=0;i<n;i++){
            int x=nums[i]^k;
            if(x>nums[i]) pq.push({x-nums[i],i});
            else{
                mini=min(mini,abs(nums[i]-(nums[i]^k)));
                ans+=nums[i];
            }
        }
        while(pq.size()>=2){
            auto x=pq.top();
            pq.pop();
            auto y=pq.top();
            pq.pop();
            ans+=x.first+y.first+nums[x.second]+nums[y.second];
        }
        if(pq.size()==1){
            auto x=pq.top();
            int gain=x.first;
            if(mini==INT_MAX || mini>gain) ans+=nums[x.second];
            else ans+=x.first+nums[x.second]-mini; 
        }
        return ans;
    }
};