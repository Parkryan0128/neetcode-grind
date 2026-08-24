class Solution {
    unordered_map<int,int> cache;
public:
    int climbStairs(int n) {
        if (n == 1) {
            return 1;
        }

        if (n == 2) {
            return 2;
        }

        if (!cache[n]) {
            cache[n] = climbStairs(n-1) + climbStairs(n-2);
        } 

        return cache[n];
    }
};
