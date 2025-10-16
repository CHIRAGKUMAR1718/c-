class Solution {
public:
    int findSmallestInteger(vector<int>& nums, int value) {
        int n=nums.size();
        unordered_map<int,int> m;
        for(int i=0;i<n;i++){
            if(nums[i]>=0) m[nums[i]%value]++;
            else m[((nums[i]%value)+value)%value]++;
        }
        int ans=0;
        while(true){
            if(m[ans%value]>0) m[ans%value]--;
            else break;
            ans++;
        }
        return ans;
    }
};