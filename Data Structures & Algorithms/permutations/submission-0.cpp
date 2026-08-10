class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> curr;
        vector<bool> visited(nums.size(), false);

        backtrack(nums, curr, visited, res);
        return res;
    }

    void backtrack(vector<int>& nums, vector<int>& curr, vector<bool>& visited, vector<vector<int>>& res) {
        if (curr.size() == nums.size()) {
            res.push_back(curr);
            return;
        }

        for (int i = 0; i < nums.size(); i++) {
            if (visited[i]) continue;

            visited[i] = true;
            curr.push_back(nums[i]);

            backtrack(nums, curr, visited, res);

            curr.pop_back();
            visited[i] = false;
        }
        return;
    }
};
