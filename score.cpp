class Solution {
public:
    void f(unordered_map<char,int>freq,vector<string>& words,int idx,int& ans,int count,vector<int>& ws){
        if (idx == words.size()) {
            ans = max(ans, count);
            return;
        }
        f(freq, words, idx + 1, ans, count, ws);
        string s = words[idx];
        bool canForm = true;
        for (char c : s) {
            freq[c]--;
            if (freq[c] < 0) canForm = false;
        }
        if (canForm)
            f(freq, words, idx + 1, ans, count + ws[idx], ws);
    }
    int ff(string s,unordered_map<char,int>& cs){
        int ans=0;
        for(int i=0;i<s.size();i++){
            ans+=cs[s[i]];
        }
        return ans;
    }
    int maxScoreWords(vector<string>& words, vector<char>& l, vector<int>& score) {
        unordered_map<char,int> cs;
        for(int i=0;i<l.size();i++) cs[l[i]]=score[l[i]-'a'];
        unordered_map<char,int> freq;
        for(int i=0;i<l.size();i++) freq[l[i]]++;
        vector<int> ws(words.size());
        for(int i=0;i<words.size();i++){
            ws[i]=ff(words[i],cs);
        }
        for(auto i:freq) cout<<i.first<<"   "<<i.second<<endl;
        int ans=INT_MIN;
        int idx=0;
        int count=0;
        f(freq,words,0,ans,count,ws);
        return ans;
    }
};