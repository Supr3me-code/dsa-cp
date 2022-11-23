class Solution {
   public:
    int numIslands(vector<vector<char>> &grid) {
        int m = grid.size(), n = m ? grid[0].size() : 0, islands = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == '1') {
                    islands++;
                    eraseIslands(grid, i, j);
                }
            }
        }
        return islands;
    }

   private:
    void eraseIslands(vector<vector<char>> &grid, int i, int j) {
        int m = grid.size(), n = grid[0].size();
        if (i < 0 || i == m || j < 0 || j == n || grid[i][j] == '0') {
            return;
        }
        grid[i][j] = '0';
        eraseIslands(grid, i - 1, j);
        eraseIslands(grid, i + 1, j);
        eraseIslands(grid, i, j - 1);
        eraseIslands(grid, i, j + 1);
    }
};

//------- graph

void bfs(int row, int column, vector<vector<int>> &vis,
         vector<vector<int>> &grid) {
    vis[row][column] = 1;
    queue<pair<int, int>> q;
    q.push({row, column});
    int r = grid.size();
    int c = grid[0].size();
    while (!q.empty()) {
        int row = q.front.first;
        int column = q.front.second;
        q.pop();

        // check all neigbors of this elememt
        for (int i = -1; i <= 1; i++) {
            for (int j = -1; j <= 1; j++) {
                int nrow = row + i;
                int ncol = column + j;

                if (nrow >= 0 && nrow < r && ncol >= 0 && ncol < c &&
                    !vis[nrow][ncol] && grid[nrow][ncol] == '1') {
                    vis[nrow][ncol] = 1;
                    q.push({nrow, ncol});
                }
            }
        }
    }
}

bool isGraphBirpatite(vector<vector<int>> &edges) {
    int row = edges.size();
    int col = edges[0].size();

    vector<vector<int>> vis(row, vector<int>(col, 0));
    int count = 0;

    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            if (!vis[i][j] && grid[i][j] == '1') {
                count++;
                bfs(i, j, vis, grid);
            }
        }
    }
    return count;
    // Write your code here.
}