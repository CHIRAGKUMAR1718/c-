class Solution {
public:
    bool checkStrings(string s1, string s2) {
        string f1="";
        string f2="";
        int n=s1.size();
        for(int i=0;i<n;i++){
            if(i%2==0) f1+=s1[i];
            else f2+=s1[i];
        }
        string ff1="";
        string ff2="";
        for(int i=0;i<n;i++){
            if(i%2==0) ff1+=s2[i];
            else ff2+=s2[i];
        }
        sort(f1.begin(),f1.end());
        sort(f2.begin(),f2.end());
        sort(ff1.begin(),ff1.end());
        sort(ff2.begin(),ff2.end());
        if(f1==ff1 && f2==ff2) return true;
        return false;
    }
};