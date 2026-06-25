class Solution {
public:
    int maxDistance(string moves) {
        int n=moves.size();
        unordered_map<char,int> m;
        for(auto i:moves){
            if(i=='_') continue;
            m[i]++;
        }
        char ch='L';
        int maxi=INT_MIN;
        for(auto i:m){
            if(i.second>maxi){
                maxi=i.second;
                ch=i.first;
            }
        }
        for(int i=0;i<n;i++) if(moves[i]=='_') moves[i]=ch;
        int sr=0;
        int sc=0;
        for(int i=0;i<n;i++){
            if(moves[i]=='L') sr--;
            if(moves[i]=='R') sr++;
            if(moves[i]=='U') sc++;
            if(moves[i]=='D') sc--;
        }
        return abs(sr)+abs(sc);
    }
};