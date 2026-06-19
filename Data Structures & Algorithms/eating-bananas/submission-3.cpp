class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int left = 1;
        int right = 0;

        for (int pile : piles) {
            right = std::max(right, pile);
        }

        int ans = right;

        while (left <= right) {
            int mid = left + (right - left) / 2;

            int hour_spent = 0;
            for (int pile : piles) {
                hour_spent += (pile + mid - 1) / mid;
            }

            if (hour_spent <= h) {
                ans = mid;
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }

        return ans;
    }
};
