class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        std::map<int,int> my_map;

        for (int i=0; i<intervals.size(); i++) {
            my_map[intervals[i][0]]++;
            my_map[intervals[i][1]]--;
        }

        int count = 0;
        vector<vector<int>> res;
        vector<int> interval;
        for (auto [key, value] : my_map) {
            if (interval.empty()) {
                interval.push_back(key);
            }
            count += value;

            if (count == 0) {
                interval.push_back(key);
                res.push_back(interval);
                interval.clear();
            }
        }

        return res;


    }
};
