class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int> count(26,0);
        for (char task: tasks) {
            count[task-'A']++;
        }

        int maxf = 0;
        for (int i=0; i<26; i++) {
            maxf = max(maxf, count[i]);
        }

        int maxCount = 0;

        for (int i=0; i<26; i++) {
            if (count[i] == maxf) maxCount++;
        }

        int time = (maxf-1) * (n + 1) + maxCount;

        return std::max(time, (int) tasks.size());
    }
};
