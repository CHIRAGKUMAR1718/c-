class Solution {
public:
    bool hasAllCodes(string s, int k) {
        unordered_map<string,int> m;
        int n=s.size();
        for(int i=0;i<=n-k;i++){
            string p=s.substr(i,k);
            m[p]++;
        }
        return pow(2,k)==m.size();
    }
};