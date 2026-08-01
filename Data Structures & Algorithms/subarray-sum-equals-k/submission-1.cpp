class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        std::unordered_map<int,int> pref;
        pref[0] = 1;
        int res = 0;
        int currSum = 0;

        for (int i=0; i<nums.size(); i++) {
            currSum += nums[i];
            int diff = currSum - k;
            res += pref[diff];
            pref[currSum]++;
        }

        return res;
    }
};