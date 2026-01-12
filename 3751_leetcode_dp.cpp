class Solution {
public:
    int totalWaviness(int num1, int num2) {
        int ans=0;
        for(int idx=num1;idx<=num2;idx++){
            string s=to_string(idx);
            for(int i=1;i<s.size()-1;i++){
                if(int(s[i])>int(s[i-1]) && int(s[i])>int(s[i+1])) ans++;
                if(int(s[i])<int(s[i-1]) && int(s[i])<int(s[i+1])) ans++;
            }
        }
        return ans;
    }
};