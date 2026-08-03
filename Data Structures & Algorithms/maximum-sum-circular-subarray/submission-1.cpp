class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int currMax = 0;
        int currMin = 0;
        int total = 0;
        int globMax = nums[0];
        int globMin = nums[0];

        for (int i=0; i< nums.size(); i++) {
            currMax = max(currMax + nums[i], nums[i]);
            currMin = min(currMin + nums[i], nums[i]);
            total += nums[i];
            globMax = max(currMax, globMax);
            globMin = min(currMin, globMin);
        }

        return globMax > 0 ? max(globMax, total-globMin) : globMax;

    }
};