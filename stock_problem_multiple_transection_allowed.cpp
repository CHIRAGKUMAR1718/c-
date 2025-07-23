
class Solution {
  public:
    int maximumProfit(vector<int> &arr) {
        // code here
        int n=arr.size();
        if(n<=1) return 0;
        int ans=0;
        int profit=0;
        int mini=arr[0];
        for(int i=1;i<n;i++){
            if(arr[i]<arr[i-1]){
                profit+=ans;
                ans=0;
                mini=arr[i];
            }
            else{
                ans=max(ans,arr[i]-mini);
            }
        }
        profit+=ans;
        return profit;
    }
};
