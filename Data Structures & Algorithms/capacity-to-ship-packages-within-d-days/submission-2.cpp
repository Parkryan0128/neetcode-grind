class Solution {
public:
    int shipWithinDays(vector<int>& weights, int days) {
        int left = 0;
        int right = 0;

        for (int item : weights) {
            right += item;
            left = max(left, item);
        }

        int res = 0;
        while (left <= right) {
            int mid = left + (right-left)/2;
            int time = 1;
            int current_weight = 0;

            for (int weight : weights) {
                if (current_weight + weight > mid) {
                    time++;
                    current_weight = weight;
                } else {
                    current_weight += weight;
                }
            }


            if (time <= days) {
                right = mid - 1;
                res = mid;
            } else {
                left = mid + 1;
            }
        }

        return res;
    }
};