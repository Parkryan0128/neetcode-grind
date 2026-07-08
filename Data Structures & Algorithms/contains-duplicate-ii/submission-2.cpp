class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        std::unordered_set<int> my_set;
        int l = 0;

        for (int r = 0; r < nums.size(); r++) {
            if (r - l > k) {
                my_set.erase(nums[l]);
                l++;
            }

            if (my_set.count(nums[r])) {
                return true;
            }

            my_set.insert(nums[r]);
        }

        return false;

    }
};