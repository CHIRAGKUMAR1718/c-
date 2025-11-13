class Solution {
public:
    int maxOperations(string s) {
        int n=s.size();
        int ans=0;
        int one=0;
        bool flag=false;
        for(int i=0;i<n;i++){
            if(s[i]=='1'){
                one++;
                flag=true;
            }
            if(s[i]=='0' && flag){
                flag=false;
                ans+=one;
            }
        }
        return ans;
    }
};