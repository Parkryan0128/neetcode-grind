/**
 * Definition of Interval:
 * class Interval {
 * public:
 *     int start, end;
 *     Interval(int start, int end) {
 *         this->start = start;
 *         this->end = end;
 *     }
 * }
 */

class Solution {
public:
    int minMeetingRooms(vector<Interval>& intervals) {
        std::map<int,int> my_map;

        for (int i=0; i<intervals.size(); i++) {
            my_map[intervals[i].start]++;
            my_map[intervals[i].end]--;
        }

        int count = 0;
        int res = 0;
        for (auto & [key, val] : my_map) {
            count += val;
            res = max(count, res);
        }

        return res;
    }
};
