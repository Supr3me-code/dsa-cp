#include <bits/stdc++.h>

int helper(vector<vector<int>> &grid, int i, int j, int row, int column,
           vector<vector<int>> &dp) {
    if (i >= row || j >= column) {
        return INT_MAX;
    }
    if (i == row - 1 && j == column - 1) {
        return grid[row - 1][column - 1];
    }
    if (dp[i][j] != -1) return dp[i][j];
    int right = helper(grid, i, j + 1, row, column, dp);
    int down = helper(grid, i + 1, j, row, column, dp);

    return dp[i][j] = grid[i][j] + min(right, down);
}

int minSumPath(vector<vector<int>> &grid) {
    int r = grid.size();
    int c = grid[0].size();
    vector<vector<int>> dp(r, vector<int>(c, -1));
    return helper(grid, 0, 0, r, c, dp);
}