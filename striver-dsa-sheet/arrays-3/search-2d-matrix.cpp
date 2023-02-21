// Write an efficient algorithm that searches for a value target in an m x n
// integer matrix matrix. This matrix has the following properties:

// Integers in each row are sorted from left to right.
// The first integer of each row is greater than the last integer of the
// previous row.

class Solution {
   public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int rows = matrix.size();
        int columns = matrix[0].size();
        int row = 0;

        for (int i = 0; i < rows; i++) {
            if (target < matrix[i][0]) {
                row = i - 1;
                break;
            } else if (target == matrix[i][0]) {
                return true;
            }
        }

        if (target < matrix[0][0] || target > matrix[rows - 1][columns - 1]) {
            return false;
        }

        if (target > matrix[rows - 1][0]) {
            row = rows - 1;
        }

        for (int i = 0; i < columns; i++) {
            if (target == matrix[row][i]) {
                return true;
            }
        }
        return false;
    }
};

class Solution {
   public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int lo = 0;
        if (!matrix.size()) return false;
        int hi = (matrix.size() * matrix[0].size()) - 1;

        while (lo <= hi) {
            int mid = (lo + (hi - lo) / 2);
            if (matrix[mid / matrix[0].size()][mid % matrix[0].size()] ==
                target) {
                return true;
            }
            if (matrix[mid / matrix[0].size()][mid % matrix[0].size()] <
                target) {
                lo = mid + 1;
            } else {
                hi = mid - 1;
            }
        }
        return false;
    }
};