class Solution {
public:
    vector<vector<int>> validArrangement(vector<vector<int>>& pairs) {
        unordered_map<int,vector<int>> graph;
        unordered_map<int,int> indegree;
        unordered_map<int,int> outdegree;
        for(auto edge:pairs){
            int sr=edge[0];
            int sc=edge[1];
            indegree[sc]++;
            outdegree[sr]++;
            graph[sr].push_back(sc);
        }
        int stt=pairs[0][0];
        for(auto ele:graph){
            int node=ele.first;
            if((outdegree[node]-indegree[node])==1){
                stt=node;
                break;
            }
        }
        vector<int> path;
        stack<int> st;
        st.push(stt);
        while(!st.empty()){
            int curr=st.top();
            if(!graph[curr].empty()){
                int neigh=graph[curr].back();
                graph[curr].pop_back();
                st.push(neigh);
            }else{
                path.push_back(curr);
                st.pop();
            }
        }
        reverse(path.begin(),path.end());
        vector<vector<int>> ans;
        for(int i=0;i<path.size()-1;i++){
            ans.push_back({path[i],path[i+1]});
        }
        return ans;
    }
};