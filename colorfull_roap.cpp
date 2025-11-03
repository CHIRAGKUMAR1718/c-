class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
        int n=colors.size();
        priority_queue<int,vector<int>,greater<int>> pq;
        pq.push(neededTime[0]);
        int ans=0;
        for(int i=1;i<n;i++){
            pq.push(neededTime[i]);
            if(colors[i]==colors[i-1]){
                ans+=pq.top();
                pq.pop();
            }
            else{
                priority_queue<int,vector<int>,greater<int>> qq;
                pq=qq;
                pq.push(neededTime[i]);
            }
        }
        return ans;
    }
};