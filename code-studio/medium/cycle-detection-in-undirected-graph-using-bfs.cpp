bool isCycle(int vertex, vector<vector<int>>& graph, vector<bool>& visited,
             vector<int>& parent) {
    visited[vertex] = true;

    queue<int> q;

    q.push(vertex);

    while (q.size() != 0) {
        int remVertex = q.front();
        q.pop();

        for (int adjVertex : graph[remVertex]) {
            if (visited[adjVertex] == false) {
                visited[adjVertex] = true;
                q.push(adjVertex);
                parent[adjVertex] = remVertex;
            }

            else if (visited[adjVertex] == true &&
                     parent[remVertex] != adjVertex) {
                return true;
            }
        }
    }
    return false;
}

string cycleDetection(vector<vector<int>>& edges, int n, int m) {
    vector<vector<int>> graph(n + 1, vector<int>());

    for (int i = 0; i < m; i++) {
        graph[edges[i][1]].push_back(edges[i][0]);
        graph[edges[i][0]].push_back(edges[i][1]);
    }

    vector<bool> visited(n + 1, false);
    vector<int> parent(n + 1, -1);

    for (int i = 1; i <= n; i++) {
        if (visited[i] == false) {
            if (isCycle(i, graph, visited, parent) == true) {
                return "Yes";
            }
        }
    }

    return "No";
}