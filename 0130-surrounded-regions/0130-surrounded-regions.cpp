class Solution {
private:
    void dfs(int row, int col, vector<vector<char>>& board, int n, int m) {
        if (row < 0 || col < 0 || row >= n || col >= m || board[row][col] != 'O')
            return;
        board[row][col] = '#';
        dfs(row - 1, col, board, n, m);
        dfs(row + 1, col, board, n, m);
        dfs(row, col - 1, board, n, m);
        dfs(row, col + 1, board, n, m);
    }
public:
    void solve(vector<vector<char>>& board) {
        int n = board.size();
        if (n == 0) return;
        int m = board[0].size();
        for (int j = 0; j < m; j++) {
            if (board[0][j] == 'O') dfs(0, j, board, n, m);
            if (board[n - 1][j] == 'O') dfs(n - 1, j, board, n, m);
        }
        for (int i = 0; i < n; i++) {
            if (board[i][0] == 'O') dfs(i, 0, board, n, m);
            if (board[i][m - 1] == 'O') dfs(i, m - 1, board, n, m);
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (board[i][j] == 'O')
                    board[i][j] = 'X';
                else if (board[i][j] == '#')
                    board[i][j] = 'O';
            }
        }
    }
};
