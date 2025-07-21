class Solution {
  public:
    vector<int> calculateSpan(vector<int>& arr) {
        int n=arr.size();
        vector<int> ans(n,1);
        stack<pair<int,int>> st;
        st.push({arr[0],0});
        for(int i=1;i<n;i++){
            int count=0;
            while(st.size()!=0 && st.top().first<=arr[i]){
                count=count+1+st.top().second;
                st.pop();
            }
            ans[i]+=count;
            st.push({arr[i],count});
        }
        return ans;
    }
};