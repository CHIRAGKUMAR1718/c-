class Solution {
public:
    struct node{
        string str;
        string sub_folder;
        bool deleted = false;
        unordered_map<string,node*> child;
        node(string val){ this->str=val; this->sub_folder=""; }
    };
    node* root;
    unordered_map<string,int> subfolder;

    void construct(vector<string> v){
        node* temp=root;
        for(auto str:v){
            if(temp->child.count(str)) temp=temp->child[str];
            else{ temp->child[str]=new node(str); temp=temp->child[str]; }
        }
    }

    void sf(node* root){
        string str__="";
        // ✅ ONLY CHANGE: sort children before serializing
        vector<pair<string,node*>> children(root->child.begin(), root->child.end());
        sort(children.begin(), children.end());
        for(auto neigh : children){
            sf(neigh.second);
            str__+="("+neigh.first+neigh.second->sub_folder+")";
        }
        root->sub_folder=str__;
        if(!str__.empty()) subfolder[str__]++;
    }

    void del(node* root){
        for(auto& curr:root->child){
            if(!curr.second->sub_folder.empty() && subfolder[curr.second->sub_folder]>1){
                curr.second->deleted = true;
            } else {
                del(curr.second);
            }
        }
    }

    void f(node* root,vector<string>& path,vector<vector<string>>& result){
        for(auto neigh:root->child){
            if(neigh.second->deleted) continue;
            path.push_back(neigh.first);
            result.push_back(path);
            f(neigh.second,path,result);
            path.pop_back();
        }
    }

    vector<vector<string>> deleteDuplicateFolder(vector<vector<string>>& paths) {
        root = new node("/");
        subfolder.clear();
        for(auto curr:paths) construct(curr);
        sf(root);
        del(root);
        vector<vector<string>> result;
        vector<string> path;
        f(root,path,result);
        return result;
    }
};