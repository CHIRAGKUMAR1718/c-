class Solution {
public:
    int smallestBalancedIndex(vector<int>& nums) {
        int n=nums.size();
        vector<unsigned long long> pre(n+1,0);
        pre[0]=0;
        vector<unsigned long long> suf(n+1,1);
        suf[n]=1;
        for(int i=0;i<n;i++) pre[i+1]=nums[i]+pre[i];
        unsigned long long total = pre[n];
        for(int i=n-1;i>=0;i--){
            if(nums[i]!=0 && suf[i+1] > total/nums[i]) suf[i] = total + 1; 
            else suf[i] = suf[i+1] * nums[i];
        }
        for(int i=0;i<n;i++){
            if(pre[i]==suf[i+1]){
                return i;
                break;
            }
        }
        return -1;
    }
};