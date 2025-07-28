class Solution {
public:
    void f(vector<vector<int>>& ans,vector<int>& nums,int idx,vector<int> v){
        ans.push_back(v);
        for(int i=idx;i<nums.size();i++){
            v.push_back(nums[i]);
            f(ans,nums,i+1,v);
            v.pop_back();
        }
    }
    int countMaxOrSubsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> v;
        int idx=0;
        f(ans,nums,idx,v);
        unordered_map<int,int> m;
        for(auto x:ans){
            if(x.size()==0) continue;
            int aa=x[0];
            for(auto y:x) aa|=y;
            m[aa]++;
        }
        int maxi=INT_MIN;
        for(auto i:m) maxi=max(maxi,i.first);
        return m[maxi];
    }
};