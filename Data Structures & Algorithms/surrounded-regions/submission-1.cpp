class Solution {
public:
    void solve(vector<vector<char>>& board) {
        int m = board.size();
        int n = board[0].size();

        for (int r = 0; r < m; r++) {
            if (board[r][0] == 'O') dfs(r, 0, board);
            if (board[r][n - 1] == 'O') dfs(r, n - 1, board);
        }
        for (int c = 0; c < n; c++) {
            if (board[0][c] == 'O') dfs(0, c, board);
            if (board[m - 1][c] == 'O') dfs(m - 1, c, board);
        }

        for (int r = 0; r < m; r++) {
            for (int c = 0; c < n; c++) {
                if (board[r][c] == 'O') {
                    board[r][c] = 'X';
                } else if (board[r][c] == 'T') {
                    board[r][c] = 'O';
                }
            }
        }
    }

private:
    void dfs(int r, int c, vector<vector<char>>& board) {
        if (r < 0 || r >= board.size() || c < 0 || c >= board[0].size() || board[r][c] != 'O') {
            return;
        }

        board[r][c] = 'T';
        dfs(r + 1, c, board);
        dfs(r - 1, c, board);
        dfs(r, c + 1, board);
        dfs(r, c - 1, board);
    }
};