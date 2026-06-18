class Solution:
    def searchMatrix(self, matrix: List[List[int]], target: int) -> bool:
        for i in range(len(matrix)):
            if target == matrix[i][0] or target == matrix[i][len(matrix[i])-1]:
                return True
            if target > matrix[i][0] or target < matrix[i][len(matrix[i])-1]:
                j = 0
                k = len(matrix[i-1])-1
                while j <= k:
                    mid = (j + k) // 2
                    if matrix[i-1][mid] == target:
                        return True
                    elif matrix[i-1][mid] > target:
                        k = mid - 1
                    else:
                        j = mid + 1        
        return False
