class Solution {
public:
    vector<string> buildArray(vector<int>& target, int n) {
        unordered_set<int> visited;
        for(auto i:target) visited.insert(i);
        vector<string> ans;
        string s="Push";
        string t="Pop";
        vector<int> check;
        for(int i=1;i<=n;i++){
            check.push_back(i);
            ans.push_back(s);
            if(!visited.count(i)){
                check.pop_back();
                ans.push_back(t);
            }
            if(check==target) break;
        }
        return ans;
    }
};