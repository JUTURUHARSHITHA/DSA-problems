class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int rows = matrix.size();
        if (rows == 0) return;

        int cols = matrix[0].size();
        vector<pair<int, int>> zero;

      
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (matrix[i][j] == 0) {
                    zero.push_back({i, j});
                }
            }
        }

        int maxi = max(cols, rows);
       
        for (auto it : zero) {
            for (int j = 0; j < maxi; j++) {
                if (j < cols) matrix[it.first][j] = 0;
                if (j < rows) matrix[j][it.second] = 0;
            }
        }
    }
};
