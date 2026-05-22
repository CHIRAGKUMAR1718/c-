class Solution {
public:
    vector<vector<int>> dir={{1,0},{0,1},{-1,0},{0,-1}};
    vector<vector<int>> target={{1,2,3},{4,5,0}};

    int bfs(vector<vector<int>>& board){
        int ans=0;
        set<vector<vector<int>>> visited;
        queue<vector<vector<int>>> q;
        q.push(board);
        visited.insert(board);
        while(!q.empty()){
            int size=q.size();
            while(size--){
                auto Board=q.front();
                q.pop();
                if(Board==target) return ans;
                int r=0;
                int c=0;
                for(int i=0;i<2;i++){
                    for(int j=0;j<3;j++){
                        if(Board[i][j]==0){
                            r=i;
                            c=j;
                        }
                    }
                }
                for(int d=0;d<4;d++){
                    int nr=r+dir[d][0];
                    int nc=c+dir[d][1];
                    if(nr<2 && nc<3 && nr>=0 && nc>=0){
                        vector<vector<int>> x=Board;
                        swap(x[r][c],x[nr][nc]);
                        if(!visited.count(x)){
                            q.push(x);
                            visited.insert(x);
                        }
                    }
                }
            }
            ans++;
        }
        return -1;
    }

    int slidingPuzzle(vector<vector<int>>& board) {
        return bfs(board);
    }
};