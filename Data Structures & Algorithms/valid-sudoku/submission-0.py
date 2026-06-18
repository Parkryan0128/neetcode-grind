class Solution:
    def isValidSudoku(self, board: List[List[str]]) -> bool:
        for i in range(0, len(board)):
            hmap_row = defaultdict(int)
            hmap_col = defaultdict(int)
            hmap_sub = defaultdict(int)
            for j in range(0, len(board)):
                if board[i][j] != "." and hmap_row[board[i][j]] != 0:
                    return False
                hmap_row[board[i][j]] += 1

                if board[j][i] != "." and hmap_col[board[j][i]] != 0:
                    return False
                hmap_col[board[j][i]] += 1
        
        for square in range(9):
            seen = set()
            for i in range(3):
                for j in range(3):
                    row = (square//3) * 3 + i
                    col = (square % 3) * 3 + j
                    if board[row][col] == ".":
                        continue
                    if board[row][col] in seen:
                        return False
                    seen.add(board[row][col])


        return True