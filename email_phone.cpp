class Solution {
public:
    string f(string&s){
        int n=s.size();
        string ans="";
        for(int i=0;i<n;i++) if(int(s[i])>=65 && int(s[i])<=90) s[i]+=32;
        ans+=s[0];
        int idx=0;
        for(int i=0;i<n;i++){
            if(s[i+1]=='@'){
                ans=ans+"*****";
                ans+=s[i];
                idx=i+1;
            }
        }
        for(int i=idx;i<n;i++) ans+=s[i];
        return ans;
    }

    string ff(string&s){
        int n=s.size();
        string phone="";
        for(int i=0;i<n;i++) if(isdigit(s[i])) phone+=s[i];
        int cc=phone.size()-10;
        int nn=phone.size();
        string ans="";
        if(cc==0) ans+="***-***-"+phone.substr(nn-4);
        if(cc==1) ans+="+*-***-***-"+phone.substr(nn-4);
        if(cc==2) ans+="+**-***-***-"+phone.substr(nn-4);
        if(cc==3) ans+="+***-***-***-"+phone.substr(nn-4);
        if(cc==4) ans+=phone.substr(nn-4);
        return ans;
    }

    string maskPII(string s) {
        bool email=false;
        bool phone=false;
        for(int i=0;i<s.size();i++) if(isdigit(s[i])) phone=true;
        if(!phone) email=true;
        if(email) return f(s);
        return ff(s);
    }
};