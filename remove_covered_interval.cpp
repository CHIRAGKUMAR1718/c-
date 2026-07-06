class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& nums) {
        int n=nums.size();
        unordered_map<int,int> m;
        for(int i=0;i<n;i++){
            int sr=nums[i][0];
            int sc=nums[i][1];
            for(int j=0;j<n;j++){
                if(i==j) continue;
                int nr=nums[j][0];
                int nc=nums[j][1];
                if(sr<=nr && sc>=nc){
                    m[j]++;
                }
            }
        }
        int count=0;
        for(auto i:m){
            if(i.second>0) count++;
        }
        return n-count;
    }
};