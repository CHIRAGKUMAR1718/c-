class Solution {
public:
    vector<int> validSequence(string word1, string word2) {
        int n=word1.size();
        int m=word2.size();
        vector<int> v(n);
        int i=m-1;
        int j=n-1;
        int count=0;
        while(j>=0){
            if(i>=0 && word1[j]==word2[i]){
                count++;
                i--;
            }
            v[j]=count;
            j--;
        }
        vector<int> ans;
        int x=0;
        bool flag=false;
        for(int k=0;k<n;k++){
            if(x>=m) break;
            if(!flag && word1[k]!=word2[x] && (k+1<n?v[k+1]:0)>=m-x-1){
                flag=true;
                ans.push_back(k);
                x++;
            }else if(word1[k]==word2[x]){
                ans.push_back(k);
                x++;
            }
        }
        if(x<m) return {};
        return ans;
    }
};