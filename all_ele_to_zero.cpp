class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n=nums.size();
        int ans=0;
        stack<int> st;
        for(int i=0;i<n;i++){
            if(st.size()==0){
                st.push(nums[i]);
                if(nums[i]!=0) ans++;
            }
            else{
                while(st.size()!=0 && st.top()>nums[i]) st.pop();
                if(st.size()==0){
                    st.push(nums[i]);
                    if(nums[i]!=0) ans++;
                }
                else if(st.top()==nums[i]) continue;
                else if(st.top()<nums[i]){
                    st.push(nums[i]);
                    if(nums[i]!=0) ans++;
                }
            }
        }
        return ans;
    }
};