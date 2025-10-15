class Solution {
public:
    int candy(vector<int>& nums) {
        int n=nums.size();
        vector<int> ans(n,1);
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        for(int i=0;i<n;i++) pq.push({nums[i],i});
        while(pq.size()!=0){
            auto curr=pq.top();
            pq.pop();
            int idx=curr.second;
            int target=curr.first;
            if(idx-1>=0 && target>nums[idx-1]){
                ans[idx]=max(ans[idx],ans[idx-1]+1);
            }
            if(idx+1<n && target>nums[idx+1]){
                ans[idx]=max(ans[idx],ans[idx+1]+1);
            }
        }
        int sum=0;
        for(auto i:ans) sum+=i;
        return sum;
    }
};