class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int left = 1;
        int right = 0;
        for (int item : piles) {
            right = max(right, item);
        }

        while (left <= right) {
            int mid = left + (right-left)/2;
            int time = 0;

            for (int item : piles) {
                time += (item+mid-1) / mid;
            }

            if (time <= h) {
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }

        return left;
    }
};
