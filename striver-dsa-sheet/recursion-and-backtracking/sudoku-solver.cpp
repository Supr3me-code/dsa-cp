// Write a program to solve a Sudoku puzzle by filling the empty cells.

// A sudoku solution must satisfy all of the following rules:

// Each of the digits 1-9 must occur exactly once in each row.
// Each of the digits 1-9 must occur exactly once in each column.
// Each of the digits 1-9 must occur exactly once in each of the 9 3x3 sub-boxes of the grid.
// The '.' character indicates empty cells.








/*
class Solution {
public:
    bool isSafe(vector<vector<char>> &board, int row, int col, int number){
        char temp = number;
        for(int i=0;i<9;i++){
            if(board[i][col] == temp) return false;
            if(board[row][i] == temp) return false;
        }
        
        int section;
        if(row<3){
            if(col<3) section = 1;
            else if(col<6) section = 2;
            else section = 3;
        }else if(row<6){
            if(col<3) section = 4;
            else if(col<6) section = 5;
            else section = 6;
        }else{
            if(col<3) section = 7;
            else if(col<6) section = 8;
            else section = 9;
        }
        
        switch(section){
            case 1: 
                for(int i=0;i<3;i++){
                    for(int j=0;j<3;j++){
                        if(board[row][col] == temp) return false;
                    }
                }
                break;
            case 2:
                for(int i=0;i<3;i++){
                    for(int j=3;j<6;j++){
                        if(board[row][col] == temp) return false;
                    }
                }
            case 3:
                for(int i=0;i<3;i++){
                    for(int j=6;j<9;j++){
                        if(board[row][col] == temp) return false;
                    }
                }
                break;
            case 4:
                for(int i=3;i<6;i++){
                    for(int j=0;j<3;j++){
                        if(board[row][col] == temp) return false;
                    }
                }
                break;
            case 5:
                for(int i=3;i<6;i++){
                    for(int j=3;j<6;j++){
                        if(board[row][col] == temp) return false;
                    }
                }
                break;
            case 6:
                for(int i=3;i<6;i++){
                    for(int j=6;j<9;j++){
                        if(board[row][col] == temp) return false;
                    }
                }
                break;
            case 7:
                for(int i=6;i<9;i++){
                    for(int j=0;j<3;j++){
                        if(board[row][col] == temp) return false;
                    }
                }
                break;
            case 8:
                for(int i=6;i<9;i++){
                    for(int j=3;j<6;j++){
                        if(board[row][col] == temp) return false;
                    }
                }
                break;
            case 9:
                for(int i=6;i<9;i++){
                    for(int j=6;j<9;j++){
                        if(board[row][col] == temp) return false;
                    }
                }
                break;
        }
        
        return true;
    }
    
    void recur(vector<vector<char>> &board, int col){
        if(col == 9){
            return;
        }
        
        for(int row = 0;row<9;row++){
            for(int number = 1;number<10;number++){
                if(isSafe(board, row, col, number)){
                    char temp = number;
                    board[row][col] = temp;
                    recur(board, col+1);
                    board[row][col] = '.';
                }
            }
        }
    }
    
    void solveSudoku(vector<vector<char>>& board) {
        recur(board, 0);
        return;
    }
};