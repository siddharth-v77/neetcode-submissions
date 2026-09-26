class Solution {
public:

    bool dfs(int src, int parent,
             vector<bool>& vis,
             vector<vector<int>>& adj) {

        vis[src] = true;

        for(int v : adj[src]) {

            if(!vis[v]) {

                if(dfs(v, src, vis, adj))
                    return true;
            }

            else if(v != parent) {
                return true;
            }
        }

        return false;
    }

    bool validTree(int n, vector<vector<int>>& edges) {

        vector<vector<int>> adj(n);

        for(auto edge : edges) {

            int u = edge[0];
            int v = edge[1];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        vector<bool> vis(n, false);

        if(dfs(0, -1, vis, adj))
            return false;

        for(int i = 0; i < n; i++) {
            if(!vis[i])
                return false;
        }

        return true;
    }
};