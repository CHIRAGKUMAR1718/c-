class Solution {
public:
    int f(int n){
        unordered_map<int,int> m;
        while(n>0){
            int x=n%10;
            m[x]++;
            n/=10;
        }
        if(m.count(3) || m.count(4) || m.count(7)) return 0;
        if(!m.count(2) && !m.count(5) && !m.count(6) && !m.count(9)) return 0;
        return 1;
    }
    int rotatedDigits(int n) {
        int ans=0;
        for(int i=1;i<=n;i++) ans+=f(i);
        return ans;
    }
};