class Solution {
public:
    int n;
    vector<list<int>> graph;

    void f(int sr, int sc) {
        graph[sr].push_back(sc);
        graph[sc].push_back(sr);
    }

    void dfs(vector<vector<int>>& parent, int root) {
        stack<pair<int,int>> st;
        st.push({root, -1});
        while (!st.empty()) {
            auto [sr, prev] = st.top();
            st.pop();
            for (auto neigh : graph[sr]) {
                if (neigh == prev) continue;
                parent[neigh][0] = sr;
                st.push({neigh, sr});
            }
        }
    }

    void fill(vector<vector<int>>& parent) {
        for (int j = 1; j < 18; j++) {
            for (int i = 1; i <= n; i++) {
                if (parent[i][j-1] == -1) parent[i][j] = -1;
                else parent[i][j] = parent[parent[i][j-1]][j-1];
            }
        }
    }

    int kth_ancestor(int node, int k, vector<vector<int>>& parent) {
        for (int i = 0; i < 18; i++) {
            if (k & (1 << i)) {
                if (node == -1) return -1;
                node = parent[node][i];
            }
            if (node == -1) return -1;
        }
        return node;
    }

    void bfs(vector<int>& depth) {
        queue<int> q;
        vector<bool> visited(n + 1, false);
        q.push(1);
        visited[1] = true;
        int prev = -1;
        while (!q.empty()) {
            int size = q.size();
            prev++;
            while (size--) {
                auto curr = q.front();
                q.pop();
                depth[curr] = prev;
                for (auto neigh : graph[curr]) {
                    if (visited[neigh]) continue;
                    q.push(neigh);
                    visited[neigh] = true;
                }
            }
        }
    }

    int res(int x) {
        long long ans = 1, base = 2, mod = 1e9 + 7;
        while (x) {
            if (x & 1) ans = (ans * base) % mod;
            base = (base * base) % mod;
            x >>= 1;
        }
        return ans;
    }

    int lca(int x, int y, vector<vector<int>>& parent) {
        if (x == y) return x;
        for (int i = 17; i >= 0; i--) {
            if (parent[x][i] == -1 || parent[y][i] == -1) continue;
            if (parent[x][i] != parent[y][i]) {
                x = parent[x][i];
                y = parent[y][i];
            }
        }
        // fix: x==y can happen if one was direct ancestor
        // if (x == y) return x;
        return parent[x][0];
    }

    vector<int> assignEdgeWeights(vector<vector<int>>& edges, vector<vector<int>>& queries) {
        n = edges.size() + 1;
        graph.resize(n + 1);
        for (auto edge : edges) f(edge[0], edge[1]);

        vector<vector<int>> parent(n + 1, vector<int>(18, -1));
        dfs(parent, 1);
        fill(parent);

        vector<int> depth(n + 1, 0);
        bfs(depth);

        vector<int> ans;
        for (auto v : queries) {
            int x = v[0], y = v[1];
            int remain = 0;

            if (depth[x] != depth[y]) {
                remain = abs(depth[x] - depth[y]);
                if (depth[x] > depth[y]) x = kth_ancestor(x, remain, parent);
                else                     y = kth_ancestor(y, remain, parent);
            }

            // fix: after leveling, x==y means one was ancestor of other
            if (x == y) {
                if (remain == 0) ans.push_back(0); // same node, 0 edges
                else ans.push_back(res(remain - 1)); // 2^(remain-1)
                continue;
            }

            int p = lca(x, y, parent);
            int dist = remain + 2 * depth[x] - 2 * depth[p]; // number of edges

            // fix: answer is 2^(dist-1), not 2^dist
            ans.push_back(res(dist - 1));
        }
        return ans;
    }
};