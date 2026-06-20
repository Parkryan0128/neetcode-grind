class Solution {
public:
    int shipWithinDays(vector<int>& weights, int days) {
        int left = 1;
        int right = 0;

        for (int weight : weights) {
            right = std::max(right, weight);
        }

        left = right;
        right *= weights.size(); 
        int ans = right;

        while (left <= right) {
            int mid = left + (right - left) / 2;
            int days_need = 1;
            int load = mid;
            for (int weight : weights) {
                if (load - weight < 0) {
                    days_need += 1;
                    load = mid - weight;
                } else {
                    load -= weight;
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