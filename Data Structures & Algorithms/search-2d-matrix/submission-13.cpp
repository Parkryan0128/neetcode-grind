class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix.size() * matrix[0].size();
        int left = 0;
        int right = n - 1;

        int row_size = matrix[0].size();

        while (left <= right) {
            int mid = left + (right-left)/2;
            int r = mid / row_size;
            int c = mid % row_size;

            if (matrix[r][c] == target) {
                return true;
            } else if (matrix[r][c] > target) {
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }

        return false;

    }
};
