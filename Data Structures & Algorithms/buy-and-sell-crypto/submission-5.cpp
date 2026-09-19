class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int max_prof = 0;
        int curr_min = prices[0];
        for (int i=0; i<prices.size(); i++) {
            int prof = prices[i] - curr_min;
            max_prof = max(prof, max_prof);
            curr_min = min(curr_min, prices[i]);
        }

        return max_prof;
    }
};
