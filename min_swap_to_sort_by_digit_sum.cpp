class Solution {
public:
    int f(int n){
        int ans=0;
        while(n>0){
            int x=n%10;
            ans+=x;
            n/=10;
        }
        return ans;
    }
    int minSwaps(vector<int>& nums) {
        int n=nums.size();
        vector<int> nums1=nums;
        sort(nums.begin(),nums.end());
        map<int,vector<int>> m;
        for(int i=0;i<n;i++){
            m[f(nums[i])].push_back(nums[i]);
        }
        vector<int> v;
        for(auto x:m){
            for(auto vv:x.second) v.push_back(vv);
        }
        unordered_map<int,int> mm;
        int count=0;
        for(int i=0;i<n;i++){
            mm[v[i]]=i;
        }
        for(int i=0;i<n;i++){
            while(nums1[i]!=v[i]){
                int j=mm[nums1[i]];
                swap(nums1[i],nums1[j]);
                count++;
            }
        }
        return count;
    }
};