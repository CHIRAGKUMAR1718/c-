class Solution {
public:
    using pp=pair<int,int>;
    int maxEvents(vector<vector<int>>& events) {
        int days=events[0][0];
        int n=events.size();
        int ans=0;
        sort(events.begin(),events.end());
        priority_queue<int,vector<int>,greater<int>> pq;
        int idx=0;
        while(!pq.empty() || idx<n){
            if(pq.size()==0) days=events[idx][0];
            while(idx<n && events[idx][0]==days){
                pq.push(events[idx][1]);
                idx++;
            }
            if(!pq.empty()){ 
                pq.pop();
                ans++;
            }

            days++;
            while(!pq.empty() && pq.top()<days) pq.pop();
        } 
        return ans;
    }
};