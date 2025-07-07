class Solution {
public:
    int maxCoins(vector<int>& nums) {
        int n=nums.size();
        n=n/3;
        priority_queue<int> ma;
        priority_queue<int,vector<int>,greater<int>> mi;
        for(auto i:nums){
            ma.push(i);
            mi.push(i);
        }
        int you=0;
        while(n>0){
            ma.pop();
            mi.pop();
            you+=ma.top();
            ma.pop();
            n--;
        }
        return you;
    }
};