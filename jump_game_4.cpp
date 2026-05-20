class Solution {
public:
    int f(vector<int>& nums,unordered_map<int,set<int>>& m){
        int n=nums.size();
        set<int> visited;
        queue<int> q;
        q.push(0);
        visited.insert(0);
        int ans=0;
        while(!q.empty()){  
            int size=q.size();
        while(size--){
            int curr=q.front();
            q.pop();
            if(curr==n-1) return ans;
            if((curr+1) < n && !visited.count(curr+1)){
                q.push(curr+1);
                visited.insert(curr+1);
            }
            if((curr-1) >=0 && !visited.count(curr-1)){
                q.push(curr-1);
                visited.insert(curr-1);
            }
            for(auto i:m[nums[curr]]){
                if(i!=curr && !visited.count(i)){
                    q.push(i);
                    visited.insert(i);
                }
            }
            m[nums[curr]].clear(); 
        }
        ans++;
        }
        return ans;
    }
    int minJumps(vector<int>& nums) {
        unordered_map<int,set<int>> m;
        for(int i=0;i<nums.size();i++) m[nums[i]].insert(i);
        return f(nums,m);
    }
};