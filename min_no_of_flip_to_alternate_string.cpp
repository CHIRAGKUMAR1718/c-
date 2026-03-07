class Solution {
public:
    int minFlips(string s) {
        s+=s;
        int n=s.size();
        string one="1";
        string zero="0";
        for(int i=1;i<n;i++){
            if(one[i-1]=='1') one+='0';
            else one+='1';
            if(zero[i-1]=='1') zero+='0';
            else zero+='1';
        }
        int ans=INT_MAX;
        int f1=0;
        int f2=0;
        for(int i=0;i<n/2;i++){
            if(s[i]!=one[i]) f1++;
            if(s[i]!=zero[i]) f2++;
        }
        ans=min({ans,f1,f2});
        for(int i=n/2;i<n;i++){
            if(s[i]!=one[i]) f1++;
            if(s[i]!=zero[i]) f2++;
            
            if(s[i-n/2]!=one[i-n/2]) f1--;
            if(s[i-n/2]!=zero[i-n/2]) f2--;

            ans=min({ans,f1,f2});
        }
        return ans;
    }
};