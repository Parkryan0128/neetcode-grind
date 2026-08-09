class Solution {
public:
vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<vector<int>> res;
        vector<int> current;
        backtrack(0, target, nums, current, res);
        return res;
    }

    void backtrack(int start, int target, vector<int>& nums, vector<int>& current, vector<vector<int>>& res) {

        if (target == 0) {
            res.push_back(current);
            return;
        }

        if (target < 0) {
            return;
        }

        for (int i = start; i < nums.size(); i++) {
            current.push_back(nums[i]);

            backtrack(i, target - nums[i], nums, current, res);

            current.pop_back();
        }
    }
};
