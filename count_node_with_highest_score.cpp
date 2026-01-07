class Solution {
public:
    int dfs(int sr,unordered_map<int,vector<int>>&mpp,unordered_map<int,vector<int>>&m){
        vector<int> v = m[sr];
        if(!mpp.count(sr))  mpp[sr] = vector<int>(2, 0);
        if(v.size() == 0) return 1;   
        if(v.size() == 1){
            int left = dfs(v[0], mpp, m);
            mpp[sr][0] += left;
            return 1 + left;  
        }
        if(v.size() == 2){
            int left = dfs(v[0], mpp, m);
            int right = dfs(v[1], mpp, m);
            mpp[sr][0] += left;
            mpp[sr][1] += right;
            return 1 + left + right;   
        }
        return -100; // safety
    }
    int countHighestScoreNodes(vector<int>& parents) {
        int n=parents.size();
        unordered_map<int,vector<int>> m;
        for(int i=1;i<n;i++)  m[parents[i]].push_back(i);
        unordered_map<long long,long long> ans;
        unordered_map<int,vector<int>> mpp;
        unordered_map<int,int> leaf;
        for(int i=1;i<=n-1;i++) if(!m.count(i)){
            leaf[i]++;
            ans[n-1]++;
        }
        dfs(0,mpp,m);
        for(auto i:mpp){
            if(leaf.count(i.first)) continue;
            int left=i.second[0];
            int right=i.second[1];
            int tot=n-1-left-right;
            if(left==0) left=1;
            if(right==0) right=1;
            if(tot==0) tot=1;
            long long x=(long long)left*right*tot;
            ans[x]++;
        }
        long long oa=0;
        for(auto i:ans) oa=max(oa,i.first);
        return ans[oa];
    }
};