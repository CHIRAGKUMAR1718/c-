class Solution {
public:
    int prefixConnected(vector<string>& words, int k) {
        unordered_map<string,int> m;
        for(auto i:words){
            if(i.size()<k) continue;
            string s=i.substr(0,k);
            m[s]++;
        }
        int ans=0;
        for(auto i:m) if(i.second>1) ans++;
        return ans;
    }
};