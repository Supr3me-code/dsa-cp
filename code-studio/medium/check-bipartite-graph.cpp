
bool helper(int node, int totalVertices, vector<vector<int>> &adj,
            vector<int> &color) {
    queue<int> q;
    q.push(0);
    color[node] = 0;
    while (!q.empty()) {
        int x = q.front();
        q.pop();
        for (auto it : adj[x]) {
            if (color[it] == -1) {
                color[it] = !color[x];
                q.push(it);
            } else if (color[it] == color[x])
                return false;
        }
    }
    return true;
}

bool isGraphBirpatite(vector<vector<int>> &edges) {
    int v = edges.size();
    vector<vector<int>> adj;
    for (int i = 0; i < v; i++) {
        for (int j = 0; j < v; j++) {
            if (edges[i][j]) adj[i].push_back(j);
        }
    }
    vector<int> color(v, -1);
    for (int i = 0; i < v; i++) {
        if (color[i] == -1) {
            if (!helper(i, v, adj, color)) return false;
        }
    }
    return true;
    // Write your code here.
}