class Solution {
public:
    vector<string> removeSubfolders(vector<string>& folder) {
        set<string> s;
        sort(folder.begin(),folder.end());
        for(int i=0;i<folder.size();i++){
            string str=folder[i];
            if(str.size()<=1) continue;
            bool flag=false;
            string tar="/";
            for(int j=1;j<str.size();j++){
                while(j<str.size() && str[j]!='/'){
                    tar+=str[j];
                    j++;
                }
                if(s.count(tar)) flag=true;
                if(flag) break;
                tar+='/';
            }
            if(!flag) s.insert(str);
        }
        vector<string> ans;
        for(auto i:s) ans.push_back(i);
        return ans;
    }
};