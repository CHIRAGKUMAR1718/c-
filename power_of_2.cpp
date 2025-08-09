class Solution {
public:
    bool isPowerOfTwo(int n) {
        if(n==0) return false;
        int count=0;
        while(n>0){
            if(n%2==1) count++;
            n/=2;
        }
        return count==1;;
    }
};