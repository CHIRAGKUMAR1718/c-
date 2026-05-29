class Solution {
public:
    vector<vector<int>> dir={{1,0},{0,1},{-1,0},{0,-1}};
    struct node{
        bool is_end;
        node* child[26];
        string word;
        node(){
            this->is_end=false;
            for(int i=0;i<26;i++) this->child[i]=NULL;
        }
    };
    void insert(node*& root,string& str){
        node* temp=root;
        for(auto ch:str){
            if(temp->child[ch-'a']==NULL){
                temp->child[ch-'a']=new node();
                temp=temp->child[ch-'a'];
            }else temp=temp->child[ch-'a'];
        }
        temp->is_end=true;
        temp->word=str;
    }

    int n,m;
    void f(int sr,int sc,vector<vector<bool>>& visited,vector<vector<char>>& board,node* root,vector<string>& ans){
        if(root->child[board[sr][sc]-'a']==NULL) return;
        root=root->child[board[sr][sc]-'a'];
        if(root->is_end){
            ans.push_back(root->word);
            root->is_end=false;
        }
        visited[sr][sc]=true;
        for(int d=0;d<4;d++){
            int nr=sr+dir[d][0];
            int nc=sc+dir[d][1];
            if(nr>=0 && nc>=0 && nr<n && nc<m && !visited[nr][nc]){
                f(nr,nc,visited,board,root,ans);
            }
        }
        visited[sr][sc]=false;
    }


    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        node* root=new node();
        for(auto str:words) insert(root,str);
        n=board.size();
        m=board[0].size();
        vector<string> ans;
        for(int i=0;i<board.size();i++){
            for(int j=0;j<board[0].size();j++){
                vector<vector<bool>> visited(n,vector<bool>(m,false));
                f(i,j,visited,board,root,ans);
            }
        }
        return ans;
    }
};