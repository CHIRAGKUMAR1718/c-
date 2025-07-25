class Solution {
public:
    unordered_map<int,vector<int>> graph;
    void dfs(int node,int parent,int& time,vector<int>& subtreeXOR,vector<int>& intime,vector<int>& outtime,vector<int>& nums){
        subtreeXOR[node]=nums[node];
        intime[node]=time;
        time++;
        for(auto neigh:graph[node]){
            if(neigh!=parent){
                dfs(neigh,node,time,subtreeXOR,intime,outtime,nums);
                subtreeXOR[node]^=subtreeXOR[neigh];
            }
        }
        time++;
        outtime[node]=time;
    }

    bool isAnsistor(int u,int v,vector<int>&intime,vector<int>&outtime){
        return intime[v]>=intime[u] && outtime[v]<=outtime[u];
    }

    int xoR(int a,int b,int c){
        int maxi=max({a,b,c});
        int mini=min({a,b,c});
        return maxi-mini;
    }

    int minimumScore(vector<int>& nums, vector<vector<int>>& edges) {
        int n=nums.size();// it give me the no. of nodes:-
        for(auto edge:edges){
            int x=edge[0];
            int y=edge[1];
            graph[x].push_back(y);
            graph[y].push_back(x);
        }
        vector<int> subtreeXOR(n,0);
        vector<int> intime(n,0);
        vector<int> outtime(n,0);
        int time=0;
        //let consider root node as 0 always samazh gye lalaaso,usko cork ke sare possible combination try marna hai:---and parent -1;
        //here we consider rooot node because we have to maintain the xor of full tree;that is subtreeXOR[0];
        dfs(0,-1,time,subtreeXOR,intime,outtime,nums);

        int result=INT_MAX;
        for(int i=1;i<n;i++){
            for(int j=i+1;j<n;j++){
                int xor1;
                int xor2;
                int xor3;
                if(isAnsistor(i,j,intime,outtime)){
                    xor1=subtreeXOR[j];
                    xor2=subtreeXOR[i]^subtreeXOR[j];
                    xor3=subtreeXOR[0]^xor1^xor2;
                }
                else if(isAnsistor(j,i,intime,outtime)){
                    xor1=subtreeXOR[i];
                    xor2=subtreeXOR[j]^subtreeXOR[i];
                    xor3=subtreeXOR[0]^xor1^xor2;
                }
                else{
                    xor1=subtreeXOR[i];
                    xor2=subtreeXOR[j];
                    xor3=subtreeXOR[0]^xor1^xor2;
                }
                result=min(result,xoR(xor1,xor2,xor3));
            }
        }
        return result;
    }
};