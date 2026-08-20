class Solution {
    unordered_map<int, vector<int>> preMap;
    unordered_set<int> visiting;
    unordered_set<int> visited;
    vector<int> output;

public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        for (int i = 0; i < numCourses; i++) {
            preMap[i] = {};
        }
        for (const auto& prereq : prerequisites) {
            preMap[prereq[0]].push_back(prereq[1]);
        }

        for (int c = 0; c < numCourses; c++) {
            if (!dfs(c)) {
                return {};
            }
        }
        return output;
    }

    bool dfs(int crs) {
        if (visiting.count(crs)) return false;
        if (visited.count(crs)) return true;
        visiting.insert(crs);
        for (int pre : preMap[crs]) {
            if (!dfs(pre)) return false;
        }
        visiting.erase(crs);

        visited.insert(crs);
        output.push_back(crs);

        return true;
    }
};