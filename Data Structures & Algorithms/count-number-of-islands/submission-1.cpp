class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int sum = 0;
        for (int i=0; i<grid.size(); i++) {
            for (int j=0; j<grid[i].size(); j++) {
                if (grid[i][j] == '1') {
                    sum +=1;
                    traverse(grid,i,j);
                }
            }

        }

        return sum;
    }

    void traverse(vector<vector<char>>& grid, int r, int c) {
        if (r < 0 || c < 0 || r >= grid.size() || c >= grid[r].size() || grid[r][c] == '0') {
            return;
        }

        grid[r][c] = '0';

        traverse(grid,r-1,c);
        traverse(grid,r+1,c);
        traverse(grid,r,c-1);
        traverse(grid,r,c+1);
    }
};
