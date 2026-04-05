class Solution {
public:
    bool judgeCircle(string moves) {
        unordered_map<char,int> m;
        for(auto i:moves) m[i]++;
        if(m['L']==m['R'] && m['U']==m['D']) return true;
        return false;
    }
};