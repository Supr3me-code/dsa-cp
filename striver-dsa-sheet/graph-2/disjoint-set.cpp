int parent[100000];
int rank[100000];

void makeSet() {
    for (int i = 1; i <= n; i++) {
        parent[i] = i;
        rank[i] = 0;
    }
}

int findPar(int node) {
    if (node == parent[node]) {
        return node;
    }
    return parent[node] = findPar(parent[node]);
}

void union(int u, int v) {
    u = findPar(u);
    v = findPar(v);
    if (rank[u] < rank[v]) {
        parent[u] = v;
    } else if (rank[u] > rank[v]) {
        parent[v] = u;
    } else {
        parent[v] = u;
        rank[u]++;
    }
}

void main() {
    makeSet();
    int m;
    cin >> m;
    while (m--) {
        int u, v;
        cin >> u >> v;
        union(u, v);

        if (findPar(u) != findPar(v)) {
            cout << "Different Component" << endl;
        } else {
            cout << "Same Component" << endl;
        }
    }
}