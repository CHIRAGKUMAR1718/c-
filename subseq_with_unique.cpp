class Solution {
public:
    int f(int idx,unordered_set<char> visited,vector<string>& arr){
        if(idx==arr.size()) return visited.size();
        string s=arr[idx];
        unordered_map<char,int> m;
        for(auto z:s) m[z]++;
        for(auto z:m) if(z.second > 1) return f(idx+1, visited, arr);
        for(auto x:s){
            if(visited.count(x)) return f(idx+1, visited, arr);
        }
        int p=f(idx+1,visited,arr);
        for(auto x:s) visited.insert(x);
        int q=f(idx+1,visited,arr);
        return max(p,q);
    }
    int maxLength(vector<string>& arr) {
        int n=arr.size();
        int ans=INT_MIN;
        unordered_set<char> visited;
        int idx=0;
        int x=f(idx,visited,arr);
        ans=max(ans,x);
        return ans;
    }
};