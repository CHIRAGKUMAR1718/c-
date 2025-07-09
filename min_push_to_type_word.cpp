class Solution {
public:
    int minimumPushes(string word) {
        int n=word.size();
        unordered_map<char,int> m;
        for(auto i:word) m[i]++;
        int ans=0;
        priority_queue<int> p;
        for(auto i:m){
            p.push(i.second);
        }
        int count=8;
        int mul=1;
        while(p.size()!=0){
            if(count==0){
                mul++;
                count=8;
            }
            ans+=(mul*p.top());
            p.pop();
            count--;
        }
        return ans;
    }
};