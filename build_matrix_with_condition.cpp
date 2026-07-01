class Solution {
public:
    vector<list<int>> graph_row;
    vector<list<int>> graph_col;
    void f(int sr,int sc){
        graph_row[sr].push_back(sc);
    }
    void ff(int sr,int sc){
        graph_col[sr].push_back(sc);
    }
    void fill_row(vector<int>& indegree){
        for(int i=1;i<indegree.size();i++){
            for(auto neigh:graph_row[i]) indegree[neigh]++;
        }
    }
    void fill_col(vector<int>& indegree){
        for(int i=1;i<indegree.size();i++){
            for(auto neigh:graph_col[i]) indegree[neigh]++;
        }
    }

    bool cycle(vector<int> indegreee,vector<list<int>> graph){
        vector<int> indegree=indegreee;
        set<int> visited;
        queue<int> q;
        for(int i=1;i<indegree.size();i++){
            if(indegree[i]==0){
                q.push(i);
                visited.insert(i);
            }
        }
        while(!q.empty()){
            int size=q.size();
            while(size--){
                auto curr=q.front();
                q.pop();
                for(auto neigh:graph[curr]){
                    if(indegree[neigh]!=0){
                        indegree[neigh]--;
                        if(indegree[neigh]==0){
                            q.push(neigh);
                            visited.insert(neigh);
                        }
                    }
                }
            }
        }
        return (visited.size()!=(indegree.size()-1));
    }

    void position(vector<int>& v,vector<list<int>> graph,vector<int> indegree){
        int idx=0;
        queue<int> q;
        for(int i=1;i<indegree.size();i++){
            if(indegree[i]==0){
                q.push(i);
                v[i]=idx++;
            }
        }
        while(!q.empty()){
            int size=q.size();
            while(size--){
                auto curr=q.front();
                q.pop();
                for(auto neigh:graph[curr]){
                    if(indegree[neigh]!=0){
                        indegree[neigh]--;
                        if(indegree[neigh]==0){
                            q.push(neigh);
                            v[neigh]=idx++;
                        }
                    }
                }
            }
        }
    }

    vector<vector<int>> buildMatrix(int k, vector<vector<int>>& rowConditions, vector<vector<int>>& colConditions) {
        graph_row.resize(k+1);
        graph_col.resize(k+1);
        set<pair<int,int>> visited;
        for(auto edge:rowConditions){
            if(!visited.count({edge[0],edge[1]})){
                f(edge[0],edge[1]);
                visited.insert({edge[0],edge[1]});
            }
        }
        visited.clear();
        for(auto edge:colConditions){
            if(!visited.count({edge[0],edge[1]})){
                ff(edge[0],edge[1]);
                visited.insert({edge[0],edge[1]});
            }
        }

        vector<int> indegree_row(k+1);
        vector<int> indegree_col(k+1);
        fill_row(indegree_row);
        fill_col(indegree_col);
        if(cycle(indegree_row,graph_row) || cycle(indegree_col,graph_col)) return {};
        vector<vector<int>> ans(k,vector<int>(k,0));
        vector<int> row(k+1);
        vector<int> col(k+1);
        position(row,graph_row,indegree_row);
        position(col,graph_col,indegree_col);

        for(int i=1;i<k+1;i++){
            ans[row[i]][col[i]]=i;
        }
        return ans;
    }
};