// Given an undirected graph and an integer M. The task is to determine if the graph can be colored with at most M colors such that no two adjacent vertices of the graph are colored with the same color. Here coloring of a graph means the assignment of colors to all vertices. Print 1 if it is possible to colour vertices and 0 otherwise.

class Solution {
public:
    void solveSudoku(vector<vector<char>>& board) {
        solve(board);
    }
    
    bool solve(vector<vector<char>> &board){
        for(int i=0;i<board.size();i++){
            for(int j=0;j<board[0].size();j++){
                
                if(board[i][j] == '.'){
                    for(char c='1';c<='9';c++){
                        if(isValid(board, i, j, c)){
                            board[i][j] = c;
                            
                            if(solve(board)) return true;
                            else board[i][j] = '.';
                        }
                    }
                    
                    return false;
                }
            }
        }
        return true;
    }
    
    bool isValid(vector<vector<char>> &board, int row, int col, char c){
        for(int i=0;i<9;i++){
            if(board[i][col] == c) return false;
            if(board[row][i] == c) return false;
            if(board[3*(row/3)+i/3][3*(col/3)+i%3] == c) return false;
        }
        return true;
    }
};