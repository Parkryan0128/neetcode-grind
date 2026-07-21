class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        std::sort(intervals.begin(), intervals.end(), [](auto& x, auto& y){
            if (x[0] == y[0]) {
                return x[1] < y[1];
            }

            return x[0] < y[0];
        });

        std::vector<vector<int>> res;
        res.push_back(intervals[0]);
        for (int i=1; i<intervals.size(); i++) {
            int start = intervals[i][0];
            int end = intervals[i][1];
            int lastEnd = res.back()[1];

            if (start <= lastEnd) {
                res.back()[1] = max(lastEnd, end);
            } else {
                res.push_back({start, end});
            }
        }

        return res;
    }
};
