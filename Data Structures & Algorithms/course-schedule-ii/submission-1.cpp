class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        unordered_map<int, vector<int>> prereq;
        for (auto& item : prerequisites) {
            prereq[item[0]].push_back(item[1]);
        }

        vector<int> output;
        unordered_set<int> cycle;
        unordered_set<int> visit;

        for (int course = 0; course < numCourses; course++) {
            if (!dfs(course, prereq, cycle, visit, output)) {
                return {};
            }
        }


        return output;
    }

    bool dfs(int course, unordered_map<int, vector<int>> & prereq, unordered_set<int> & cycle, unordered_set<int>& visit, vector<int>& output) {
        if (cycle.count(course)) {
            return false;
        }

        if (visit.count(course)) {
            return true;
        }

        cycle.insert(course);
        if (prereq.count(course)) {
            vector<int> prereq_list = prereq[course];
            for (int item : prereq_list) {
                if (!dfs(item, prereq, cycle, visit, output)) {
                    return false;
                }
            }
        }
        cycle.erase(course);
        visit.insert(course);
        output.push_back(course);
        return true;
    }
};
