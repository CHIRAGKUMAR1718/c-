class Solution {
public:
    bool f(int n){
        vector<int> v(10,0);
        while(n>0){
            int x=n%10;
            v[x]++;
            n/=10;
        }
        for(int i=0;i<10;i++){
            if(v[i]!=0 && v[i]!=i) return false;
        }
        return true;
    }
    int nextBeautifulNumber(int n) {
        for(int i=1;i<=1224444;i++){
            if(i>n && f(i)) return i;
        }
        return 0;
    }
};