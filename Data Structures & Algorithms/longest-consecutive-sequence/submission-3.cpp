class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        std::unordered_set<int> my_set(nums.begin(), nums.end());
        int res = 0;


        for (int item : my_set) {
            if (my_set.find(item-1) == my_set.end()) {
                int length = 1;
                while (my_set.find(item+length) != my_set.end()) {
                    length++;
                }
                res = max(res,length);
            }
        }

        return res;
    }
};
