class Solution {
public:
    int n,m;
    bool check(int sr,int sc,int oor,int ooc,vector<vector<int>>& mat){
        if(oor<0 || oor>=n || ooc<0 || ooc>=m) return false;
        int type=mat[oor][ooc];
        if(type==1){
            if(oor==sr && ooc+1==sc) return true;
            if(oor==sr && ooc-1==sc) return true;
        }
        if(type==2){
            if(oor+1==sr && ooc==sc) return true;
            if(oor-1==sr && ooc==sc) return true;
        }
        if(type==3){
            if(oor+1==sr && ooc==sc) return true;
            if(oor==sr && ooc-1==sc) return true;
        }
        if(type==4){
            if(oor==sr && ooc+1==sc) return true;
            if(oor+1==sr && ooc==sc) return true;
        }
        if(type==5){
            if(oor-1==sr && ooc==sc) return true;
            if(oor==sr && ooc-1==sc) return true;
        }
        if(type==6){
            if(oor==sr && ooc+1==sc) return true;
            if(oor-1==sr && ooc==sc) return true;
        }
        return false;
    }
    bool f(int sr,int sc,vector<vector<int>>& mat,vector<vector<int>>& visited,bool flag){
        if(sr==n-1 && sc==m-1) return flag;
        if(flag==false) return false;
        if(sr>=n || sr<0 || sc<0 || sc>=m || visited[sr][sc]==1) return false;
        if(mat[sr][sc]==1){
            bool flag1=check(sr,sc,sr,sc+1,mat);
            bool flag2=check(sr,sc,sr,sc-1,mat);
            visited[sr][sc]=1;
            if(f(sr,sc+1,mat,visited,flag1) | f(sr,sc-1,mat,visited,flag2)) return true;
            visited[sr][sc]=0;
        }
        else if(mat[sr][sc]==2){
            bool flag1=check(sr,sc,sr+1,sc,mat);
            bool flag2=check(sr,sc,sr-1,sc,mat);
            visited[sr][sc]=1;
            if(f(sr+1,sc,mat,visited,flag1) | f(sr-1,sc,mat,visited,flag2)) return true;
            visited[sr][sc]=0;
        }
        else if(mat[sr][sc]==3){
            bool flag1=check(sr,sc,sr+1,sc,mat);
            bool flag2=check(sr,sc,sr,sc-1,mat);
            visited[sr][sc]=1;
            if(f(sr+1,sc,mat,visited,flag1) | f(sr,sc-1,mat,visited,flag2)) return true;
            visited[sr][sc]=0;
        }
        else if(mat[sr][sc]==4){
            bool flag1=check(sr,sc,sr+1,sc,mat);
            bool flag2=check(sr,sc,sr,sc+1,mat);
            visited[sr][sc]=1;
            if(f(sr+1,sc,mat,visited,flag1) | f(sr,sc+1,mat,visited,flag2)) return true;
            visited[sr][sc]=0;
        }
        else if(mat[sr][sc]==5){
            bool flag1=check(sr,sc,sr,sc-1,mat);
            bool flag2=check(sr,sc,sr-1,sc,mat);
            visited[sr][sc]=1;
            if(f(sr,sc-1,mat,visited,flag1) | f(sr-1,sc,mat,visited,flag2)) return true;
            visited[sr][sc]=0;
        }
        else if(mat[sr][sc]==6){
            bool flag1=check(sr,sc,sr,sc+1,mat);
            bool flag2=check(sr,sc,sr-1,sc,mat);
            visited[sr][sc]=1;
            if(f(sr,sc+1,mat,visited,flag1) | f(sr-1,sc,mat,visited,flag2)) return true;
            visited[sr][sc]=0;
        }
        return false;
    }
    bool hasValidPath(vector<vector<int>>& mat) {
        n=mat.size();
        m=mat[0].size();
        vector<vector<int>> visited(n,vector<int>(m,0));
        return f(0,0,mat,visited,true);
    }
};