class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& nums) {
        int n=nums.size();
        vector<int> ans(n,0);
        stack<pair<int,int>> st;
        ans[n-1]=0;
        st.push({nums[n-1],0});
        int idx=n-2;
        while(st.size()!=0 && idx>=0){
            int sum=0;
            while(st.size()!=0 && nums[idx]>=st.top().first){
                sum+=st.top().second;
                st.pop();
            }
            if(st.size()!=0){
                ans[idx]=sum+1;
                st.push({nums[idx],ans[idx]});
            }
            else{
                ans[idx]=0;
                st.push({nums[idx],0});
            }
            idx--;
        }
        return ans;
    }
};