class Solution {
public:
    using pp=pair<char,int>;
    string smallestPalindrome(string s) {
        int n=s.size();
        priority_queue<pp,vector<pp>,greater<pp>> pq;
        unordered_map<char,int> m;
        for(auto i:s) m[i]++;
        for(auto i:m) pq.push({i.first,i.second});
        vector<char> v(n);
        int idx=0;
        while(!pq.empty()){
            auto curr=pq.top();
            pq.pop();
            if(curr.second==0) continue;
            if(curr.second>=2){
                v[idx]=curr.first;
                v[n-idx-1]=curr.first;
                pq.push({curr.first,curr.second-2});
                idx++;
            }else{
                v[n/2]=curr.first;
            }
        }
        string ans="";
        for(auto i:v) ans+=i;
        return ans; 
    }
};