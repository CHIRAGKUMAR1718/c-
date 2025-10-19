class Solution {
public:
    string mini;
    void f(int i,string s,string&target,vector<int> count){
        int n=target.size();
        if(i==n){
            if(s>target) mini=min(mini,s);
            return;
        }
        if(count[target[i]-'a']>0){
            count[target[i]-'a']--;
            f(i+1,s+target[i],target,count);
            count[target[i]-'a']++;
        }
        for(int j=target[i]-'a'+1;j<26;j++){
            if(count[j]>0){
                s+='a'+j;
                count[j]--;
                for(int k=0;k<26;k++){
                    while(count[k]>0){
                        s+='a'+k;
                        count[k]--;
                    }
                }
                mini=min(mini,s);
                return;
            }
        }
    }
    string lexGreaterPermutation(string s, string target) {
        vector<int> count(26,0);
        sort(s.rbegin(),s.rend());
        if(s<=target) return "";
        mini=s;
        for(auto i:s) count[i-'a']++;
        f(0,"",target,count);
        return mini;
    }
};