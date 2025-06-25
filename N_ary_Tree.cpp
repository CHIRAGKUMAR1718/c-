class Solution {
public:
    void bfs(vector<vector<int>>& ans, Node* root) {
        if(root==NULL) return;
        queue<Node*> q;
        q.push(root);
        Node* yoo = new Node(-1);
        q.push(yoo);
        vector<int> v;
        while (!q.empty()) {
            Node* curr = q.front();
            q.pop();
            if (curr->val == -1) {
                ans.push_back(v);
                v.clear();
                if (!q.empty())  
                    q.push(new Node(-1));
            } else {
                v.push_back(curr->val);
                for (Node* child : curr->children)
                    if (child != NULL) q.push(child);
            }
        }
    }
    vector<vector<int>> levelOrder(Node* root) {
        vector<vector<int>> ans;
        bfs(ans, root);
        return ans;
    }
};
