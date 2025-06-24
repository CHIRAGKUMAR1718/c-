class Solution {
public:
    void f(vector<string>&ans,string str,int&n){
        if(str.size()==n){
            ans.push_back(str);
            return;
        }
        if(str.size()==0 || str[str.size()-1]!='a') f(ans,str+"a",n);
        if(str.size()==0 || str[str.size()-1]!='b') f(ans,str+"b",n);
        if(str.size()==0 || str[str.size()-1]!='c') f(ans,str+"c",n);
    }
    string getHappyString(int n, int k) {
        vector<string> ans;
        f(ans,"",n);
        if(k>ans.size()) return "";
        return ans[k-1];
    }
};