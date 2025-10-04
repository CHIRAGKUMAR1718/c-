class Solution {
public:
    vector<vector<int>> dir={{1,0},{0,1},{-1,0},{0,-1}};
    void f(priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>>& pq,vector<vector<int>>& height,vector<vector<int>>& visited,int& ans){
        while(pq.size()!=0){
            auto curr=pq.top();
            pq.pop();
            for(int d=0;d<4;d++){
                int nr=dir[d][0]+curr.second.first;
                int nc=dir[d][1]+curr.second.second;
                if(nr>=0 && nc>=0 && nr<n && nc<m && visited[nr][nc]==0){
                    visited[nr][nc]=1;
                    ans+=max(curr.first-height[nr][nc],0);
                    pq.push({max(curr.first,height[nr][nc]),{nr,nc}});
                }
            }
        }
    }
    int n;
    int m;
    int trapRainWater(vector<vector<int>>& height) {
        n=height.size();
        m=height[0].size();
        vector<vector<int>> visited(n,vector<int>(m,0));
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>> pq;
        int ans=0;
        for(int i=0;i<n;i++){
            pq.push({height[i][0],{i,0}});
            pq.push({height[i][m-1],{i,m-1}});
            visited[i][0]=1;
            visited[i][m-1]=1;
        }
        for(int i=1;i<m-1;i++){
            pq.push({height[0][i],{0,i}});
            pq.push({height[n-1][i],{n-1,i}});
            visited[0][i]=1;
            visited[n-1][i]=1;
        }
        f(pq,height,visited,ans);
        return ans;
    }
};