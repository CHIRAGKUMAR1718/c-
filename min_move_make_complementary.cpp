class Solution {
public:
    int minMoves(vector<int>& nums, int limit) {
        int n=nums.size();
        vector<int> pre(2*limit+2);
        for(int i=0;i<n/2;i++){
            int a=nums[i];
            int b=nums[n-i-1];
            int mini=min(a,b)+1;
            int maxi=limit+max(a,b);
            pre[2]+=2;
            pre[2*limit+1]-=-2;
            pre[mini]+=-1;
            pre[maxi+1]-=-1;
            pre[a+b]+=-1;
            pre[a+b+1]-=-1;
        }
        for(int i=3;i<2*limit+1;i++) pre[i]=pre[i]+pre[i-1];
        int mini=INT_MAX;
        for(int i=2;i<2*limit+1;i++){
            cout<<pre[i]<<"  ";
            mini=min(mini,pre[i]);
        }
        return mini;
    }
};