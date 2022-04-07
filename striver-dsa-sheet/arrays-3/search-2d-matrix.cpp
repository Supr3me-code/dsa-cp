class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int rows = matrix.size();
        int columns = matrix[0].size();
        int row = 0;
        
        for(int i=0;i<rows;i++){
            if(target<matrix[i][0]){
                row = i-1;
                break;
            }else if(target==matrix[i][0]){
                return true;
            }
        }
        
        if(target<matrix[0][0] || target>matrix[rows-1][columns-1]){
            return false;
        }
        
        if(target>matrix[rows-1][0]){
            row = rows-1;
        }
        
        for(int i=0;i<columns;i++){
            if(target==matrix[row][i]){
                return true;
            }
        }
        return false;
    }
};