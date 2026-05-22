class Solution {
public:
    bool isZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        int n=nums.size();
        vector<int> pre(n+1,0);
        for(auto i:queries){
            pre[i[0]]+=-1;
            pre[i[1]+1]-=-1;
        }
        for(int i=1;i<pre.size();i++) pre[i]=pre[i]+pre[i-1];
        for(int i=0;i<n;i++) nums[i]+=pre[i];
        for(auto i:nums) if(i>0) return false;
        return true;
    }
};