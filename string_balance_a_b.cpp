class Solution {
public:
    int minimumDeletions(string s) {
        stack<char> st;
        int count=0;
        for(int i=0;i<s.size();i++){
            if(st.size()==0) st.push(s[i]);
            else if(s[i]=='a' && st.top()=='b'){
                count++;
                st.pop();
            }else st.push(s[i]);
        }
        return count;
    }
};