class Solution {
public:
    bool f(string& s){
        int count=0;
        for(auto i:s) if(i=='1') count++;
        return count==1 && s[s.size()-1]=='1';
    }
    void solve(string& s,int& ans){
        if(f(s)) return;
        if(s[s.size()-1]=='0'){
            for(int i=s.size()-1;i>=1;i--){
                if(s[i]=='0' && s[i-1]=='1'){
                    s[i]='1';
                    s[i-1]='0';
                }
            }
        }else{
            for(int i=s.size()-1;i>=0;i--){
                if(s[i]=='0'){
                    s[i]='1';
                    break;
                }else s[i]='0';
            }
        }
        ans++;
        solve(s,ans);
    }
    int numSteps(string s) {
        int ans=0;
        if(f(s)) return ans;
        string str="0";
        str+=s;
        solve(str,ans);
        return ans;
    }
};