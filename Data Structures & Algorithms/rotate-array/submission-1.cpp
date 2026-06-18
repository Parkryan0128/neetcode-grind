class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int shift = k % nums.size();

        std::reverse(nums.begin(), nums.end());
        std::reverse(nums.begin(), nums.begin()+shift);
        std::reverse(nums.begin()+shift,nums.end());
    }
};