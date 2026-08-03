class Solution {
public:
    int jump(vector<int>& nums) {
        int currEnd = 0;
        int jumps = 0;
        int maxReach = 0;

        for (int i=0; i< nums.size()-1; i++) {
            maxReach = max(maxReach, i + nums[i]);

            if (i == currEnd) {
                currEnd = maxReach;
                jumps++;
            }
        }

        return jumps;

    }
};
