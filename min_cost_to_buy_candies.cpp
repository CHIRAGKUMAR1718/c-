class Solution {
public:
    int minimumCost(vector<int>& cost) {
        sort(cost.begin(),cost.end());
        int n=cost.size();
        int i=n-3;
        while(i>=0){
            cost[i]=0;
            i-=3;
        }
        int ans=0;
        for(auto i:cost) ans+=i;
        return ans;
    }
};