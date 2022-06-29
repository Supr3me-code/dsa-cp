class Solution {
   public:
    void findTopSort(int node, vector<int>& visited, stack<int>& st,
                     vector<int> adj[]) {
        visited[node] = 1;
        for (auto it : adj[node]) {
            if (!visited[it]) {
                findTopSort(it, visited, st, adj);
            }
        }
        st.push(node);
    }
    // Function to return list containing vertices in Topological order.
    vector<int> topoSort(int V, vector<int> adj[]) {
        stack<int> st;
        vector<int> visited(V, 0);
        for (int i = 0; i < V; i++) {
            if (visited[i] == 0) {
                findTopSort(i, visited, st, adj);
            }
        }
        vector<int> topo;
        while (!st.empty()) {
            topo.push_back(st.top());
            st.pop();
        }
        return topo;
        // code here
    }
};
