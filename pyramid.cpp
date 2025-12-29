class Solution {
public:
    unordered_map<string,bool> dp;
    bool f(string curr,unordered_map<string,vector<char>>&m,int idx,string next){
        if(curr.size()==1) return true;
        string key=curr+" "+to_string(idx)+" "+next;
        if(dp.count(key)) return dp[key];
        if(idx==curr.size()-1) return dp[key]=f(next,m,0,"");
        string now=curr.substr(idx,2);
        if(!m.count(now)) return dp[key]=false;
        for(auto i:m[now]){
            next.push_back(i);
            if(f(curr,m,idx+1,next)) return dp[key]=true;
            next.pop_back();
        }
        return dp[key]=false;
    }
    bool pyramidTransition(string bottom, vector<string>& allowed) {
        unordered_map<string,vector<char>> m;
        for(auto i:allowed) m[i.substr(0,2)].push_back(i[2]);
        return f(bottom,m,0,"");
    }
};