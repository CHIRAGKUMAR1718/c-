class Solution {
public:
    int f(int i,int j,string& s,string& t){
        int count=0;
        int nc=0;
        while(i<s.size() && j<t.size()){
            if(s[i]!=t[j]) nc++;
            if(nc==1) count++;
            if(nc>1) break;
            i++;
            j++;
        }
        return count;
    }
    int countSubstrings(string s, string t) {
        int n=s.size();
        int m=t.size();
        int ans=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                ans+=f(i,j,s,t);
            }
        }
        return ans;
    }
};