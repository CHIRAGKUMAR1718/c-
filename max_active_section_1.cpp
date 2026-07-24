class Solution {
public:
    int maxActiveSectionsAfterTrade(string s) {
        vector<int> co;
        int n=s.size();
        int count=0;
        int count_one=0;
        for(int i=0;i<n;i++){
            if(s[i]=='1'){ 
                count_one++;
                if(count!=0) co.push_back(count);
                count=0;
            }else count++;
        }
        if(count!=0) co.push_back(count);
        int ans=count_one;
        int maxi=0;
        for(int i=1;i<co.size();i++){
            maxi=max(maxi,co[i]+co[i-1]);
        }
        return ans+maxi;
    }
};