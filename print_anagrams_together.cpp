// User function Template for C++

class Solution {
  public:
    vector<vector<string>> anagrams(vector<string>& arr) {
        int n=arr.size();
        unordered_map<string,vector<int>> m;
        for(int i=0;i<n;i++){
            string s=arr[i];
            sort(s.begin(),s.end());
            m[s].push_back(i);
        }
        vector<vector<string>> ans;
        for(auto v:m){
            vector<string> yy;
            for(auto i:v.second) yy.push_back(arr[i]);
            ans.push_back(yy);
        }
        return ans;
    }
};