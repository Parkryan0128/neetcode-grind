class Solution {
public:
    int shipWithinDays(vector<int>& weights, int days) {
        int left = 0;
        int right = 0;

        for (int weight : weights) {
            left = std::max(left, weight);
            right += weight;
        }

        int ans = right;

        while (left <= right) {
            int mid = left + (right - left) / 2;
            int days_need = 1;
            int current_weight = 0;

            for (int weight : weights) {
                if (current_weight + weight > mid) {
                    days_need += 1;
                    current_weight = weight;
                } else {
                    current_weight += weight;
                }
            }

            if (days_need <= days) {
                ans = mid;
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }

        return ans;
    }
};