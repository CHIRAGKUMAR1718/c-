class Solution {
public:
    using ll=long long;
    using pp=pair<ll,pair<ll,ll>>;
    long long minNumberOfSeconds(int h, vector<int>& nums) {
        priority_queue<pp,vector<pp>,greater<pp>> pq;
        for(auto i:nums) pq.push({i,{i,1}});
        int cnt=0;              
        ll ans=0;               
        while(cnt<h){
            auto x=pq.top();
            pq.pop();
            ans=x.first;        
            ll a=x.first;
            ll b=x.second.first;
            ll c=x.second.second+1;
            a=b*((c*(c+1))/2);
            pq.push({a,{b,c}});
            cnt++;
        }
        return ans;             
    }
};