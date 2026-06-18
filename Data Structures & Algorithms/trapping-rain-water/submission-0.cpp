class Solution {
public:
    int trap(vector<int>& height) {
        int res = 0;
        int left = 0;
        int right = height.size()-1;

        int left_max = height[left];
        int right_max = height[right];

        while (left < right) {
            if (left_max > right_max) {
                right--;
                right_max = std::max(right_max, height[right]);
                res += right_max - height[right];
            } else {
                left++;
                left_max = std::max(left_max, height[left]);
                res += left_max - height[left];
            }
        }

        return res;

    }
};
