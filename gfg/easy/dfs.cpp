class Solution {
   public:
    void dfs(int idx, vector<int> &visited, vector<int> adj[],
             vector<int> &storeDfs) {
        storeDfs.push_back(idx);
        visited[idx] = 1;
        for (auto it : adj[idx]) {
            if (!visited[it]) {
                dfs(it, visited, adj, storeDfs);
            }
        }
    }

    vector<int> dfsOfGraph(int V, vector<int> adj[]) {
        vector<int> storeDfs;
        vector<int> visited(V + 1, 0);
        for (int i = 0; i < V; i++) {
            if (!visited[i]) {
                dfs(i, visited, adj, storeDfs);
            }
        }
        return storeDfs;
    }
};
