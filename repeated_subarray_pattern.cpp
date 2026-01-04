class Solution {
public:
    bool f(int k,string&s){
        int n=s.size();
        string target=s.substr(0,k);
        string ch=target;
        while(target.size()!=n) target+=ch;
        return target==s;
    }
    bool repeatedSubstringPattern(string s) {
        int n=s.size();
        if(n==1) return false;
        set<char> st;
        for(auto i:s) st.insert(i);
        if(st.size()==1) return true;
        for(int i=2;i<=sqrt(n);i++){
            if(n%i==0){
                if(f(i,s) || f(n/i,s)) return true;
            }
        }
        return false;
    }
};