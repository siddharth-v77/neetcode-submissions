class Solution {
public:

    void bfs(int src , vector<bool>& vis , vector<vector<int>> &graph){
        queue<int> q ;
        q.push(src);
        vis[src] = true;

        while(!q.empty()){
            int a = q.front();
            q.pop();

            for(auto v : graph[a]){
                if(!vis[v]){
                    vis[v] = true;
                    q.push(v);
                }
            }
        }
    }

    int countComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>> graph(n);
        int count = 0;
        vector<bool> vis(n,false);
        for(auto edge : edges){
            int u = edge[0];
            int v = edge[1];

            graph[u].push_back(v);
            graph[v].push_back(u);
        }

        for(int i= 0 ; i < n ; i++){
            if(!vis[i]){
                bfs(i , vis , graph);
                count++;
            }
        }
        return count ;
    }
};
