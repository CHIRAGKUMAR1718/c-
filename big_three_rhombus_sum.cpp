class Solution {
public:
    int n,m;
    void f(int sr,int sc,vector<vector<int>>& grid,set<int>& st){
    st.insert(grid[sr][sc]); 
    for(int len=1;len<min(n,m);len++){
        int sum=0;
        if(sr-len<0 || sr+len>=n || sc-len<0 || sc+len>=m) break;
        int r=sr-len, c=sc;
        for(int i=0;i<len;i++) sum+=grid[r+i][c+i];
        for(int i=0;i<len;i++) sum+=grid[r+len+i][c+len-i];
        for(int i=0;i<len;i++) sum+=grid[r+2*len-i][c-i];
        for(int i=0;i<len;i++) sum+=grid[r+len-i][c-len+i];
        st.insert(sum);
    }
}
//main chiz yahi tha ke tum cells ko center of rombus ke tarah dekho then charo vertex find karo then traverse...
    vector<int> getBiggestThree(vector<vector<int>>& grid) {
        n=grid.size();
        m=grid[0].size();
        set<int> st;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                f(i,j,grid,st);
            }
        }
        vector<int> ans;
        for(auto it=st.rbegin();it!=st.rend();it++){
            if(ans.size()==3) break;
            ans.push_back(*it);
        }
        return ans;
    }
};