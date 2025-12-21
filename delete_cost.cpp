class Solution {
public:
using pp=pair<long long,char>;
    long long minCost(string s, vector<int>& cost) {
        int n=s.size();
        unordered_map<char,long long> m;
        for(int i=0;i<n;i++) m[s[i]]+=cost[i];
        long long ans=0;
        priority_queue<pp,vector<pp>,greater<pp>> p;
        for(auto i:m) p.push({i.second,i.first});
        while(p.size()>1){
            ans+=p.top().first;
            p.pop();
        }
        return ans;
    }
};