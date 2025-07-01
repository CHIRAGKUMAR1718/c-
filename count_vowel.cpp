class Solution {
public:
    void f(vector<char>& v,int& ans,string& str,int n,int idx){
        if(str.size()==n){
            ans++;
            return;
        }
        for(int i=idx;i<5;i++){
            str+=v[i];
            f(v,ans,str,n,i);
            str.pop_back();
        }
    }
    int countVowelStrings(int n) {
        vector<char> v={'a','e','i','o','u'};
        int ans=0;
        string str="";
        f(v,ans,str,n,0);
        return ans;
    }
};