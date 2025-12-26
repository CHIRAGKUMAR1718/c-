class Solution {
public:
    long long maximumHappinessSum(vector<int>& nums, int k) {
        int n=nums.size();
        long long ans=0;
        long long count=0;
        priority_queue<int> p;
        for(auto i:nums) p.push(i);
        while(k--){
            if(p.top()==0) break;
            if(p.top()<count) break;
            ans+=p.top()-count;
            p.pop();
            count++;
        }
        return ans;
    }
};