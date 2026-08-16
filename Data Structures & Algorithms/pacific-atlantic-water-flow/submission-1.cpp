class Solution {
    vector<pair<int,int>> directions = {{1,0}, {-1,0}, {0,1}, {0,-1}};
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int row_size = heights.size();
        int col_size = heights[0].size();
        vector<vector<bool>> pac(row_size, vector<bool>(col_size, false));
        vector<vector<bool>> atl(row_size, vector<bool>(col_size, false));

        for (int c = 0 ; c < col_size; c++) {
            dfs(0, c, pac, heights);
            dfs(row_size-1, c, atl, heights);
        }

        for (int r = 0; r < row_size; r++) {
            dfs(r, 0, pac, heights);
            dfs(r, col_size-1, atl, heights);
        }

        vector<vector<int>> res;
        for (int i=0; i<row_size; i++) {
            for (int j=0; j<col_size; j++) {
                if (pac[i][j] && atl[i][j]) {
                    res.push_back({i, j});
                }
            }
        }

        return res;
    }
private:
    void dfs(int r, int c, vector<vector<bool>> & ocean, vector<vector<int>>& height) {
        ocean[r][c] = true;

        for (auto [dr, dc] : directions) {
            int nr = dr + r;
            int nc = dc + c;
            if (nr >= 0 && nr < height.size() && nc >= 0 && nc < height[0].size() && !ocean[nr][nc] && height[nr][nc] >= height[r][c]) {
                dfs(nr,nc,ocean,height);
            }
        }
    }

};
