class Solution {
   public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> graph = buildGraph(numCourses, prerequisites);
        vector<int> degrees = computeIndegrees(graph);

        for (int i = 0; i < numCourses; i++) {
            int j = 0;
            for (; j < numCourses; j++) {
                if (!degrees[j]) {
                    break;
                }
            }
            if (j == numCourses) {
                return false;
            }
            degrees[j]--;
            for (int v : graph[j]) {
                degrees[v]--;
            }
        }
        return true;
    }

   private:
    vector<vector<int>> buildGraph(int n, vector<vector<int>>& pre) {
        vector<vector<int>> graph(n);
        for (auto p : pre) {
            graph[p[1]].push_back(p[0]);
        }
        return graph;
    }

    vector<int> computeIndegrees(vector<vector<int>>& graph) {
        vector<int> degrees(graph.size(), 0);
        for (auto g : graph) {
            for (int node : g) {
                degrees[node]++;
            }
        }
        return degrees;
    }
};