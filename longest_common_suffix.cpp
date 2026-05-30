class Solution {
public:
    struct node{
        int len;
        int idx;
        int child[26];
        node(){
            this->len=INT_MAX;
            this->idx=INT_MAX;
            for(int i=0;i<26;i++) this->child[i]=-1;
        }
    };
    vector<node> pool;
    int root;
    int newnode(){
        pool.push_back(node());
        return pool.size()-1;
    }
    void insert(string& str,int index){
        int length=str.size();
        int temp=root;
        if(pool[temp].len>length){
            pool[temp].len=length;
            pool[temp].idx=index;
        }
        for(auto ch:str){
            if(pool[temp].child[ch-'a']==-1) pool[temp].child[ch-'a']=newnode();
            temp=pool[temp].child[ch-'a'];
            if(pool[temp].len>length){
                pool[temp].len=length;
                pool[temp].idx=index;
            }
        }
    }
    int f(string& str){
        int temp=root;
        int ans=pool[temp].idx;
        for(int i=0;i<str.size();i++){
            if(pool[temp].child[str[i]-'a']==-1) break;
            temp=pool[temp].child[str[i]-'a'];
            ans=pool[temp].idx;
        }
        return ans;
    }
    vector<int> stringIndices(vector<string>& wordsContainer, vector<string>& wordsQuery) {
        pool.reserve(500005);
        root=newnode();
        for(int i=0;i<wordsContainer.size();i++){
            string str=wordsContainer[i];
            reverse(str.begin(),str.end());
            insert(str,i);
        }
        int n=wordsQuery.size();
        vector<int> ans(n);
        for(int i=0;i<n;i++){
            string str=wordsQuery[i];
            reverse(str.begin(),str.end());
            ans[i]=f(str);
        }
        return ans;
    }
};