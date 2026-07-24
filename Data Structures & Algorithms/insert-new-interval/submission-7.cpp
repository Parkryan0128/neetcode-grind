class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> res;

        int newStart = newInterval[0];
        int newEnd = newInterval[1];

        for (int i=0; i<intervals.size(); i++) {
            if (intervals[i][0] > newInterval[1]) {
                res.push_back(newInterval);
                for (int j=i; j < intervals.size(); j++) {
                    res.push_back(intervals[j]);
                }
                return res;
            } else if (intervals[i][1] < newInterval[0]) {
                res.push_back(intervals[i]);
            } else {
                newInterval[0] = min(newInterval[0], intervals[i][0]);
                newInterval[1] = max(newInterval[1], intervals[i][1]);
            }
        }

        res.push_back(newInterval);
        return res;
        
    }
};
