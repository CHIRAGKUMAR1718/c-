class Solution {
public:
    void bfs(int init,vector<bool>& visited,vector<bool>& a_k,vector<vector<int>>& keys,vector<vector<int>>& containedBoxes,vector<bool>& a_b){
        a_b[init]=true;
        if(a_k[init]==false) return;
        queue<int> q;
        q.push(init);
        visited[init]=true;
        while(!q.empty()){
            auto curr=q.front();
            q.pop();
            for(auto i:keys[curr]){
                a_k[i]=true;
                if(a_b[i] && !visited[i]){
                    q.push(i);
                    visited[i]=true;
                }
            }
            for(auto i:containedBoxes[curr]){
                a_b[i]=true;
                if(!visited[i] && a_k[i]){
                    q.push(i);
                    visited[i]=true;
                }
            }
        }
    }
    int maxCandies(vector<int>& status, vector<int>& candies, vector<vector<int>>& keys, vector<vector<int>>& containedBoxes, vector<int>& initialBoxes) {
        int n=status.size();
        vector<bool> a_k(n,false);
        vector<bool> a_b(n,false);
        for(int i=0;i<n;i++) if(status[i]==1) a_k[i]=true;
        vector<bool> visited(n,false);
        for(auto i:initialBoxes){
            if(visited[i]==true) continue;
            bfs(i,visited,a_k,keys,containedBoxes,a_b);
        }
        int ans=0;
        for(int i=0;i<n;i++) if(visited[i]) ans+=candies[i];
        return ans;
    }
};