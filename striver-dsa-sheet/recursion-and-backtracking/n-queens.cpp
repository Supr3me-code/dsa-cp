// The n-queens puzzle is the problem of placing n queens on an n x n chessboard
// such that no two queens attack each other.

// Given an integer n, return all distinct solutions to the n-queens puzzle. You
// may return the answer in any order.

// Each solution contains a distinct board configuration of the n-queens'
// placement, where 'Q' and '.' both indicate a queen and an empty space,
// respectively.

class Solution {
   public:
    bool isSafe(int row, int col, vector<string> board, int n) {
        int storeRow = row;
        int storeCol = col;

        while (row >= 0 && col >= 0) {
            if (board[row][col] == 'Q') return false;
            row--;
            col--;
        }

        row = storeRow;
        col = storeCol;
        while (col >= 0) {
            if (board[row][col] == 'Q') return false;
            col--;
        }

        row = storeRow;
        col = storeCol;
        while (row < n && col >= 0) {
            if (board[row][col] == 'Q') return false;
            col--;
            row++;
        }

        return true;
    }

   public:
    void recur(int col, vector<string> &board, vector<vector<string>> &result,
               int n) {
        if (col == n) {
            result.push_back(board);
            return;
        }

        for (int row = 0; row < n; row++) {
            if (isSafe(row, col, board, n)) {
                board[row][col] = 'Q';
                recur(col + 1, board, result, n);
                board[row][col] = '.';
            }
        }
    }

   public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> result;
        vector<string> board(n);
        string s(n, '.');
        for (int i = 0; i < n; i++) {
            board[i] = s;
        }
        recur(0, board, result, n);
        return result;
    }
};