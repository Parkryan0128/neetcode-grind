class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        bool row[9][9] = {false};
        bool col[9][9] = {false};
        bool square[9][9] = {false};

        for (int r = 0; r < 9; r++) {
            for (int c = 0; c < 9; c++) {
                if (board[r][c] == '.') continue;

                int val = board[r][c] - '1';
                int boxId = (r / 3) * 3 + c / 3;

                if (row[r][val] || col[c][val] || square[boxId][val]) {
                    return false;
                }

                row[r][val] = true;
                col[c][val] = true;
                square[boxId][val] = true;
            }
        }

        return true;
    }
};
