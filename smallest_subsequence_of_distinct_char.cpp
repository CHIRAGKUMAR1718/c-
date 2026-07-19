class Solution {
public:
    string smallestSubsequence(string s) {
        int n=s.size();
        stack<char> st;
        unordered_map<char,int> m;
        for(auto i:s) m[i]++;
        set<char> visited;
        int idx=0;
        while(idx<n){
            while(st.size()!=0 && st.top()>s[idx] && m[st.top()]>0 && !visited.count(s[idx])){
                visited.erase(st.top());
                st.pop();
            }
            if(!visited.count(s[idx])){
                st.push(s[idx]);
                visited.insert(s[idx]);
            }
            m[s[idx]]--;
            idx++;
        }
        string ans="";
        while(st.size()!=0){
            ans+=st.top();
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};