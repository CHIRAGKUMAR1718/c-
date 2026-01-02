class Solution {
public:
    using pp=pair<long long,pair<int,int>>;
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        vector<vector<int>> ans;
        int n=nums1.size();
        int m=nums2.size();
        set<pair<int,int>> visited;
        priority_queue<pp,vector<pp>,greater<pp>> pq;
        long long sum=nums1[0]+nums2[0];
        pq.push({sum,{0,0}});
        visited.insert({0,0});
        while(k-- && pq.size()!=0){
            auto curr=pq.top();
            pq.pop();
            int i=curr.second.first;
            int j=curr.second.second;
            ans.push_back({nums1[i],nums2[j]});
            if(i+1<n && !visited.count({i+1,j})){
                sum=(long long)nums1[i+1]+nums2[j];
                pq.push({sum,{i+1,j}});
                visited.insert({i+1,j});
            }
            if(j+1<m && !visited.count({i,j+1})){
                sum=(long long)nums1[i]+nums2[j+1];
                pq.push({sum,{i,j+1}});
                visited.insert({i,j+1});
            }
        } 
        return ans;
    }
};