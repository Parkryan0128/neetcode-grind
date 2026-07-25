class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        vector<vector<int>> res;
        res.push_back(intervals[0]);

        for (int i=1; i<intervals.size(); i++) {
            int start = intervals[i][0];
            int end = intervals[i][1];
            int prevEnd = res[res.size()-1][1];

            if (start <= prevEnd) {
                res[res.size()-1][1] = max(prevEnd, end);
            } else {
                res.push_back({start, end});
            }
        }

        return res;
    }
};
