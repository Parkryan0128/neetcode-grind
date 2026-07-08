class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        std::unordered_set<int> my_set;
        int l = 0;
        int res = 0;

        for (int r=0; r<s.size(); r++) {
            while (my_set.count(s[r])) {
                my_set.erase(s[l]);
                l++;
            }
            my_set.insert(s[r]);
            res = std::max(res, r - l + 1);
        }

        return res;
    }
};
