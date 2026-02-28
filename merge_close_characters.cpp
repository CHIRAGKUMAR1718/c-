class Solution {
public:
    string mergeCharacters(string s, int k) {
        string ans="";
        int len=k+1;
        set<char> st;
        int idx=0;
        for(int i=0;i<s.size();i++){
            if(st.size()==len) st.erase(ans[idx++]);
            if(!st.count(s[i])) ans+=s[i];
            st.insert(s[i]);
        }
        return ans;
    }
};©leetcode