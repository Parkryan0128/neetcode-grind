class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        std::unordered_set<int> res;

        for (int i=0; i< nums.size(); i++) {
            res.insert(nums[i]);
        }

        return res.size() != nums.size();
    }
};