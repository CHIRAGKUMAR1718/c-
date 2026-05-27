class Solution {
public:
    int numberOfSpecialChars(string word) {
        unordered_map<char,int> m;
        int n=word.size();
        for(int i=0;i<n;i++){
            if(int(word[i])>=97 && int(word[i])<=122) continue;
            if(m.count(word[i])) continue;
            else m[word[i]]=i;
        }
        vector<bool> flag(26,false);
        for(int i=0;i<n;i++){
            if(int(word[i])>=97 && int(word[i])<=122){
                if(m.count(word[i]-32)){
                    if(i<m[word[i]-32]) flag[word[i]-'a']=true;
                    else flag[word[i]-'a']=false;
                }
            }
        }
        int ans=0;
        for(auto i:flag) if(i) ans++;
        return ans;
    }
};