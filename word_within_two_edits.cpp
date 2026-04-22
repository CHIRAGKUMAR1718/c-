class Solution {
public:
    vector<string> twoEditWords(vector<string>& queries, vector<string>& dictionary) {
        vector<string> ans;
        for(int i=0;i<queries.size();i++){
            for(int j=0;j<dictionary.size();j++){
                int count=0;
                string str1=dictionary[j];
                string str2=queries[i];
                for(int k=0;k<dictionary[0].size();k++){
                    if(str1[k]!=str2[k]) count++;
                }
                if(count<=2){
                    ans.push_back(queries[i]);
                    break;
                }
            }
        }
        return ans;
    }
};