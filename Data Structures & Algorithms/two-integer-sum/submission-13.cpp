class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        std::unordered_map<int,int> my_map;

        for (int i=0; i<nums.size(); i++) {
            int find = target - nums[i];
            if (my_map[find] > 0) {
                return {my_map[find]-1, i};
            }

            my_map[nums[i]] = i+1;
        }

        return {};
    }
};
