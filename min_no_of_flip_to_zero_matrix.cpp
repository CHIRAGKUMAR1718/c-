class Solution {
public:
    int n,m;


    int f(vector<vector<int>>& mat){
        set<vector<vector<int>>> visited;
        queue<vector<vector<int>>> q;
        vector<vector<int>> target(n,vector<int>(m,0));
        q.push(mat);
        visited.insert(mat);
        int ans=0;
        while(!q.empty()){
            int size=q.size();
            while(size--){
                auto curr=q.front();
                q.pop();
                if(curr==target) return ans;
                for(int i=0;i<n;i++){
                    for(int j=0;j<m;j++){
                        vector<vector<int>> grid=curr;
                            grid[i][j]=!grid[i][j];
                            if(i+1<n) grid[i+1][j]=!grid[i+1][j];
                            if(j+1<m) grid[i][j+1]=!grid[i][j+1];
                            if(i-1>=0) grid[i-1][j]=!grid[i-1][j];
                            if(j-1>=0) grid[i][j-1]=!grid[i][j-1];
                            if(!visited.count(grid)){
                                visited.insert(grid);
                                q.push(grid);
                            }
                    }
                }
            }
            ans++;
        }
        return -1;
    }


    int minFlips(vector<vector<int>>& mat) {
        n=mat.size();
        m=mat[0].size();
        return f(mat);
    }
};