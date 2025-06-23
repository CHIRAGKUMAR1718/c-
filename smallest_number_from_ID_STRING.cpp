class Solution {
public:
    bool f(string& ans, vector<int>& d, string& str, int idx, unordered_set<int>& visited) {
        if (idx == str.size()) return true;
        if (ans.size() == str.size() + 1) return true;
        if (str[idx] == 'I') {
            for (int i = 1; i <= 9; i++) {
                if (!visited.count(i) && (ans.back() - '0') < i) {  
                    visited.insert(i);
                    ans += to_string(i);
                    if (f(ans, d, str, idx + 1, visited)) return true;
                    ans.pop_back();
                    visited.erase(i);
                }
            }
            return false;  
        } else {
            for (int i = 1; i <= 9; i++) {
                if (!visited.count(i) && (ans.back() - '0') > i) {  
                    visited.insert(i);
                    ans += to_string(i);
                    if (f(ans, d, str, idx + 1, visited)) return true;
                    ans.pop_back();
                    visited.erase(i);
                }
            }
            return false;
        }
    }

    string smallestNumber(string str) {
        vector<int> d = {1,2,3,4,5,6,7,8,9};
        for (int i = 1; i <= 9; i++) {
            unordered_set<int> visited;
            string ans = "";
            int idx = 0;
            ans += to_string(i);
            visited.insert(i);  
            if (f(ans, d, str, idx, visited)) return ans;
        }
        return "chirag_bro";
    }
};
