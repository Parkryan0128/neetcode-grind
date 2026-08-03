class Solution {
public:
    bool canReach(string s, int minJump, int maxJump) {
        queue<int> q;
        int farthest = 0;
        int n = s.size();
        q.push(0);

        while(!q.empty()) {
            int i = q.front();
            q.pop();
            int start = max(i+minJump, farthest+1);

            for (int j=start; j < min(i+maxJump+1, n); j++) {
                if (s[j] == '0') {
                    if (j == n-1) {
                        return true;
                    }
                    q.push(j);
                }
            }

            farthest = i+maxJump;
        }

        return false;
    }
};