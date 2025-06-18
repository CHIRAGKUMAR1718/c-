class Solution {
public:
    void f(vector<vector<int>>&ans,vector<int>output,int idx,vector<int>&nums){
        ans.push_back(output);
        for(int i=idx;i<nums.size();i++){
            if(i>idx && nums[i]==nums[i-1]) continue;
            output.push_back(nums[i]);
            f(ans,output,i+1,nums);
            output.pop_back();
        }
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<vector<int>> ans;
        vector<int> output;
        f(ans,output,0,nums);
        return ans;
    }
};