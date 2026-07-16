class Solution {
public:
    int n,m;
    using pp=pair<long long,pair<long long,long long>>;
    vector<vector<int>> dir={{0,1},{1,0},{-1,0},{0,-1}};
    int dj(vector<vector<int>>& mat){
        vector<vector<long long>> parent(n,vector<long long>(m,INT_MAX));
        priority_queue<pp,vector<pp>,greater<pp>> pq;
        pq.push({0,{0,0}});
        parent[0][0]=0;
        vector<vector<int>> visited(n,vector<int>(m,0));
        while(!pq.empty()){
            auto curr=pq.top();
            pq.pop();
            auto sr=curr.second.first;
            auto sc=curr.second.second;
            auto sum=curr.first;
            if(sr==n-1 && sc==m-1) return sum;
            if(visited[sr][sc]==1) continue;
            visited[sr][sc]=1;
            for(auto d=0;d<4;d++){
                int nr=sr+dir[d][0];
                int nc=sc+dir[d][1];
                if(nr>=0 && nc>=0 && nr<n && nc<m && visited[nr][nc]==0){
                    int val=((nr+nc)%2==1)?1:2;
                    long long next=mat[nr][nc];
                    long long newsum=max(sum,next)+val;
                    if(parent[nr][nc]>newsum){  
                        pq.push({newsum,{nr,nc}});
                        parent[nr][nc]=newsum;
                    }
                }
            }
        }
        return parent[n-1][m-1];
    }
    int minTimeToReach(vector<vector<int>>& mat) {
        n=mat.size();
        m=mat[0].size();
        return dj(mat);
    }
};