class Solution {
public:
    int timeRequiredToBuy(vector<int>& tickets, int k) {
        int n=tickets.size();
        queue<pair<int,int>> q;
        for(int i=0;i<n;i++){
            q.push({tickets[i],i});
        }
        int time=0;
        while(true){
            time++;
            auto curr=q.front();
            q.pop();
            curr.first-=1;
            if(curr.first!=0) q.push({curr});
            if(curr.first==0 && k==curr.second) break;
        }
        return time;
    }
};