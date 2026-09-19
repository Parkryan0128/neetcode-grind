class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        std::unordered_set<int> my_set;

        for (int i=0; i<nums.size(); i++) {
            my_set.insert(nums[i]);
        }

        int longest = 0;
        for (auto& item : my_set) {
            if (!my_set.count(item-1)) {
                int count = 1;
                int current = item + 1;
                while (my_set.count(current)) {
                    current += 1;
                    count += 1;
                }
                longest = max(longest, count);
            }
        }

        return longest;
    }
};
