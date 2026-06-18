class Solution {
public:
    int maxArea(vector<int>& heights) {
        int i =0;
        int j = heights.size()-1;
        int max_area = 0;

        while (i < j) {
            if (heights[i] > heights[j]) {
                
                max_area = std::max(max_area, heights[j] * (j-i));
                j--;
            } else {
                max_area = std::max(max_area, heights[i] * (j-i));
                i++;
            }
        }


        return max_area;
    }
};
