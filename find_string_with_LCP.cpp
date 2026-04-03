class Solution {
public:
    int n;
    bool sym(vector<vector<int>>& lcp){
        int k=n;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(i==j){
                    if(lcp[i][j]!=k) return false;
                    else k-=1;
                }
                else if(lcp[i][j]!=lcp[j][i]) return false;
                else if(lcp[i][j]>n-j) return false;
            }
        }
        return true;
    }

    int f(string& ans,int i,int j,vector<vector<int>>& mat){
        if(i>=n || j>=n) return 0;
        if(ans[i]!=ans[j]) return 0;
        else return 1+f(ans,i+1,j+1,mat);
    }

    string findTheString(vector<vector<int>>& lcp) {
        n=lcp.size();
        if(!sym(lcp)) return "";
        unordered_map<int,vector<int>> m;
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                if(lcp[i][j]>0){
                    m[j].push_back(i);
                }
            }
        }
        string ans="a";
        char ch='b';
        for(int i=1;i<n;i++){
            if(m[i].size()==0){
                if(ch<97 || ch>122) return "";
                ans+=ch;
                ch++;
            }
            else ans+=ans[m[i][0]];
        }
        vector<vector<int>> mat=lcp;
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                mat[i][j]=f(ans,i,j,mat);
            }
        }
        if(mat!=lcp) return "";
        return ans;
    }
};