class Solution {
public:
    vector<int> exclusiveTime(int n, vector<string>& logs) {
        vector<int> ans(n,0);
        stack<pair<int,int>> st;
        for(int i=0;i<logs.size();i++){
            string s=logs[i];
            string i_d="";
            string s_e="";
            string t_s="";
            int idx=0;
            for(int j=0;j<s.size();j++){
                if(s[j]==':') break;
                else i_d+=s[j];
                idx=j;
            }
            if(s[idx+2]=='s') s_e="start";
            else s_e="end";
            idx+=2;
            if(s_e=="start") idx+=6;
            else idx+=4;
            for(int j=idx;j<s.size();j++) t_s+=s[j];
            int id=stoi(i_d);
            int ts=stoi(t_s);
            if(s_e == "start") {
                st.push({id, ts});
            } 
            else { 
                auto pp = st.top();
                st.pop();
                int total = ts - pp.second + 1;
                ans[pp.first] += total;
                if (!st.empty()) {
                    ans[st.top().first] -= total;
                }
            }
        }
        return ans;
    }
};