/*
// Definition for Employee.
class Employee {
public:
    int id;
    int importance;
    vector<int> subordinates;
};
*/
class Solution {
public:
    unordered_map<int,pair<int,vector<int>>> m;
    void f(int &id,int& ans){
        ans+=m[id].first;
        for(auto curr:m[id].second){
            f(curr,ans);
        }
    }
    int getImportance(vector<Employee*> employees, int id) {
        for(auto emp:employees) m[emp->id]={emp->importance,emp->subordinates};
        int ans=0;
        f(id,ans);
        return ans;
    }
};