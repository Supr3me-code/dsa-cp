class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int rows = matrix.size();
        
        //transpose
        for(int i=0;i<rows;i++){
            for(int j=0;j<i;j++){
                swap(matrix[i][j], matrix[j][i]);
            }
        }
        
        //reverse each row
        for(int i=0;i<rows;i++){
            reverse(matrix[i].begin(), matrix[i].end());
        }
        
        return;
    }
};