class Solution {
public:
    int maxArea(vector<int>& heights) {
        int i = 0;
        int j = heights.size() -1;

        int max_area = 0;
        while (i < j) {
            int curr_max = min(heights[i], heights[j]) * (j-i);
            max_area = max(curr_max, max_area);

            if (heights[i] > heights[j]) {
                j--;
            } else {
                i++;
            }
        }


        return max_area;
    }
};
