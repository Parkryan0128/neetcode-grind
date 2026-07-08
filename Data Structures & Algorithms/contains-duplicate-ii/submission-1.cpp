class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        std::unordered_set<int> my_set;

        int j = 0;

        for (int i=0; i< nums.size(); i++) {
            if (!my_set.count(nums[i])) {
                if (i - j == k) {
                    my_set.erase(nums[j]);
                    j++;
                }
                my_set.insert(nums[i]);
            } else {
                return true;
            }
        }

        return false;
    }
};