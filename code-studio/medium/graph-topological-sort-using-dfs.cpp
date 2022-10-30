#include <bits/stdc++.h>

void dfs(int node, stack<int> &st, vector<int> &vis, vector<vector<int>> &adj) {
    vis[node] = 1;
    for (auto i : adj[node]) {
        if (!vis[i]) {
            dfs(i, st, vis, adj);
        }
    }
    st.push(node);
}

vector<int> topologicalSort(vector<vector<int>> &edges, int v, int e) {
    vector<vector<int>> adj(v, vector<int>());
    vector<int> vis(v, 0);
    stack<int> st;
    vector<int> result;

    for (int i = 0; i < e; i++) {
        adj[edges[i][0]].push_back(edges[i][1]);
    }

    for (int i = 0; i < v; i++) {
        if (!vis[i]) {
            dfs(i, st, vis, adj);
        }
    }

    while (!st.empty()) {
        result.push_back(st.top());
        st.pop();
    }

    return result;
    // Write your code here
}