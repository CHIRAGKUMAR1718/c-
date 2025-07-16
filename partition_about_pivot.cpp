class Solution {
public:
    static bool cmp(pair<int,int>a,pair<int,int> b){
        return a.second<b.second;
    }
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        int n=nums.size();
        vector<pair<int,int>> s;
        vector<pair<int,int>> l;
        int count=0;
        for(int i=0;i<n;i++){
            if(nums[i]<pivot){  
                s.push_back({nums[i],i});
            }
            else if(nums[i]>pivot) l.push_back({nums[i],i});
            else count++;
        }
        sort(s.begin(),s.end(),cmp);
        sort(l.begin(),l.end(),cmp);
        vector<int> ans;
        for(int i=0;i<s.size();i++) ans.push_back(s[i].first);
        while(count--) ans.push_back(pivot);
        for(int i=0;i<l.size();i++) ans.push_back(l[i].first);
        return ans;
    }
};