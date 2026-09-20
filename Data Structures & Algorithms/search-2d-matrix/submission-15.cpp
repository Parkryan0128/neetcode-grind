class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix.size() * matrix[0].size();


        int left = 0;
        int right = n-1;

        while (left <= right) {
            int mid = left + (right-left)/2;
            int r = mid / matrix[0].size();
            int c = mid % matrix[0].size();

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
