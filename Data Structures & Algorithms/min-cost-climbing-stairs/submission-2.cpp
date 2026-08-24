class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        
        unordered_map<int,int> dp;
        dp[0] = 0;
        dp[1] = 0;
        int n = cost.size();
        for (int i=2; i < n+1; i++) {
            dp[i] = min(dp[i-1] + cost[i-1], dp[i-2] + cost[i-2]);
        }

        return dp[n];
    }
};
