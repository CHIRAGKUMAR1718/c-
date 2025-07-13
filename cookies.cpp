class Solution {
public:
    int findContentChildren(vector<int>& players, vector<int>& trainers) {
        priority_queue<int,vector<int>,greater<int>> p;
        priority_queue<int,vector<int>,greater<int>> t;
        for(auto i:players) p.push(i);
        for(auto i:trainers) t.push(i);
        int ans=0;
        while(p.size()!=0 && t.size()!=0){
            if(p.top()<=t.top()){
                p.pop();
                t.pop();
                ans++;
            }
            else t.pop();
        }
        return ans;
    }
};