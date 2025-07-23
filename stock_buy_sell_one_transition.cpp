class Solution {
  public:
    int maximumProfit(vector<int> &arr) {
        // code here
        int n=arr.size();
        int ans=0;
        if(n<=1) return 0;
        int mini=arr[0];
        for(int i=1;i<n;i++){
            ans=max(ans,arr[i]-mini);
            mini=min(mini,arr[i]);
        }
        return ans;
    }
};
