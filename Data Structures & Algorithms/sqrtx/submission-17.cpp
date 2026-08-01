class Solution {
public:
    int mySqrt(int x) {
        if (x < 2) return x;

        long left = 1;
        long right = x / 2;

        while (left <= right) {
            int mid = left + (right-left)/2;
            if ((long long) mid * mid  == x) {
                return mid;
            } else if ((long long) mid * mid  > x) {
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }

        return right;
    }
};