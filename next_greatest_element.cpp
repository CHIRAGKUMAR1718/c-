class Solution {
  public:
    vector<int> nextLargerElement(vector<int>& arr) {
        int n=arr.size();
        vector<int> ans(n,-1);
        stack<int> st;
        st.push(arr[n-1]);
        for(int i=n-2;i>=0;i--){
            while(st.size()!=0 && st.top()<=arr[i]) st.pop();
            if(st.size()!=0) ans[i]=st.top();
            st.push(arr[i]);
        }
        return ans;
    }
};