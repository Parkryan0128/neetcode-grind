class Solution:
    def maxAreaOfIsland(self, grid: List[List[int]]) -> int:
        if len(grid) == 0:
            return 0

        directions = [[-1,0],[1,0],[0,-1],[0,1]]

        row = len(grid)
        col = len(grid[0])
        max_area = 0

        def dfs(r,c):
            if r < 0 or c < 0 or r == row or c == col or grid[r][c] == 0:
                return 0
            
            grid[r][c] = 0
            area = 1
            for i, j in directions:
                area += dfs(r+i,c+j)
            
            return area


        for i in range(row):
            for j in range(col):
                if grid[i][j] == 1:
                    max_area = max(max_area, dfs(i,j))

        
        return max_area