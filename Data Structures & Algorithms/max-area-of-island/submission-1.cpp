class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int max_area = 0;
        for (int i=0; i<grid.size(); i++) {
            for (int j=0; j < grid[i].size(); j++) {
                if (grid[i][j] == 1) {
                    max_area = max(max_area, dfs(grid,i,j));
                }
            }
        }
        return max_area;
    }


    int dfs(vector<vector<int>>& grid, int r, int c) {
        if (r < 0 || c < 0 || r >= grid.size() || c >= grid[r].size() || grid[r][c] == 0) {
            return 0;
        }


        grid[r][c] = 0;
        return dfs(grid,r+1,c) + dfs(grid,r-1,c) + dfs(grid,r,c+1) + dfs(grid,r,c-1) + 1;
    }
};
