class Solution {
public:
    bool am(vector<int>&nums,int l,int r){
        vector<int> v;
        for(int i=l;i<=r;i++){
            v.push_back(nums[i]);
        }
        if(v.size()<=2) return true;
        sort(v.begin(),v.end());
        int d=v[1]-v[0];
        for(int i=1;i<v.size();i++){
            if(v[i]-v[i-1]!=d) return false;
        }
        return true;
    }
    vector<bool> checkArithmeticSubarrays(vector<int>& nums, vector<int>& l, vector<int>& r) {
        vector<bool> ans;
        for(int i=0;i<l.size();i++){
            ans.push_back(am(nums,l[i],r[i]));
        }
        return ans;
    }
};