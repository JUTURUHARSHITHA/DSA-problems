class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        int rows[9] = {0};
        int columns[9] = {0};
        int squares[9] = {0};
        
        for (int i = 0; i < 9; ++i) {
            for (int j = 0; j < 9; ++j) {
                if (board[i][j] != '.') {
                    int num = board[i][j] - '1';
                    int squareIndex = (i / 3) * 3 + (j / 3);
                    if ((rows[i] & (1 << num)) || 
                        (columns[j] & (1 << num)) || 
                        (squares[squareIndex] & (1 << num))) {
                        return false;
                    }
                    rows[i] |= (1 << num);
                    columns[j] |= (1 << num);
                    squares[squareIndex] |= (1 << num);
                }
            }
        }
        return true;
    }
};