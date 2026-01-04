class Solution {
public:
    bool rotateString(string s, string goal) {
        int n=s.size();
        string original=s;
        int count=0;
        while(count<=n){
            if(original==goal) return true;
            string st=original.substr(0,n-1);
            original=original[n-1]+st;
            count++;
        }
        return false;
    }
};