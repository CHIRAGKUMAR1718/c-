class Solution {
public:
    int minSwaps(string s) {
        int n=s.size();
        stack<char> st;
        for(int i=0;i<n;i++){
            if(st.size()==0) st.push(s[i]);
            else{
                if(s[i]==']' && st.top()=='[') st.pop();
                else st.push(s[i]);
            }
        }
        int x=st.size()/2;
        if(x%2==0) return x/2;
        return (x+1)/2;
    }
};