class Solution {
public:
//LEETCODE 1689;
    int minPartitions(string s) {
       int n=s.size();
       int maxi=0;
       for(int i=0;i<n;i++){
        int p=s[i]-'0';
        maxi=max(maxi,p);
       }
       return maxi;
    }
};