class Solution {
   public:
    vector<int> findBall(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();

        vector<int> result;

        for (int j = 0; j < cols; j++) {
            int currentPosition = j;
            int nextPosition;
            for (int i = 0; i < rows; i++) {
                nextPosition = currentPosition + grid[i][currentPosition];
                if (nextPosition < 0 || nextPosition >= cols ||
                    grid[i][currentPosition] != grid[i][nextPosition]) {
                    currentPosition = -1;
                    break;
                }
                currentPosition = nextPosition;
            }
            result.push_back(currentPosition);
        }
        return result;
    }
};