class Solution {
public:

    int f(string s,unordered_map<char,char>&m){
        unordered_map<char,int> count;
        for(auto i:s) count[i]++;
        set<char> st;
        int ans=0;
        for(int i=0;i<s.size();i++){
            if(st.count(s[i])) continue;
            int f1=count[s[i]];
            int f2=count[m[s[i]]];
            ans+=abs(f1-f2);
            st.insert(s[i]);
            st.insert(m[s[i]]);
        }
        return ans;
    }

    int mirrorFrequency(string s) {
        vector<char> v1(26);
        vector<char> v2(26);
        char ch1='a';
        char ch2='z';
        for(int i=0;i<26;i++){
            v1.push_back(ch1);
            v2.push_back(ch2);
            ch1++;
            ch2--;
        }
        unordered_map<char,char> m;
        for(int i=0;i<26;i++) m[v1[i]]=v2[i];
        vector<char> n1(10);
        vector<char> n2(10);
        char x1='0';
        char x2='9';
        for(int i=0;i<10;i++){
            n1.push_back(x1);
            n2.push_back(x2);
            x1++;
            x2--;
        }
        for(int i=0;i<10;i++) m[n1[i]]=n2[i];
        for(auto i:m) cout<<i.first<<" -> "<<i.second<<endl;
        return f(s,m);
    }
};