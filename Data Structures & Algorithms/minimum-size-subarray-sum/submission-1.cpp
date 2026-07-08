class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int sum = 0;
        int l = 0;
        int res = nums.size() + 1;

        for (int r = 0; r < nums.size(); r++) {
            sum += nums[r];

            while (sum >= target) {
                res = std::min(res, r - l + 1);
                sum -= nums[l];
                l++;
            }
        }

        if (res == nums.size() + 1) return 0;

        return res;

    }
};