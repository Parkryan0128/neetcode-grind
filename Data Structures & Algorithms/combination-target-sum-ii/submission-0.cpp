class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        vector<int> current;
        sort(candidates.begin(), candidates.end());
        backtrack(0, candidates, current, target, res);
        return res;

    }

    void backtrack(int start, vector<int>& candidates, vector<int>& current, int target, vector<vector<int>>& res) {
        if (target == 0) {
            res.push_back(current);
        }

        if (target < 0) {
            return;
        }

        for (int i=start; i < candidates.size(); i++) {
            if (i > start && candidates[i] == candidates[i - 1]) {
                continue;
            }
            current.push_back(candidates[i]);

            backtrack(i+1, candidates, current, target - candidates[i], res);

            current.pop_back();
        }
    }
};
