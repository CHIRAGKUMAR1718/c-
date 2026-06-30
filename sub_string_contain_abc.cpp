class Solution {
public:
    bool f(unordered_map<char,int>& m){
        if(m['a'] && m['b'] && m['c']) return true;
        return false;
    }
    int numberOfSubstrings(string s) {
        int n=s.size();
        unordered_map<char,int> m;
        int i=0;
        int j=0;
        int ans=0;
        m[s[0]]++;
        while(j<n && i<n){
            if(f(m)){
                ans+=n-j;
                m[s[i]]--;
                i++;
            }
            else{
                j++;
                m[s[j]]++;
            }
        }
        return ans;
    }
};