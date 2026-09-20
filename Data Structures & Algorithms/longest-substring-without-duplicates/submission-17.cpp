class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        std::unordered_map<char,int> my_map;
        int l = 0;
        int max_count = 0;

        for (int i=0; i<s.size(); i++) {
            if (my_map.count(s[i])) {
                l = max(l, my_map[s[i]] + 1);
            }
            my_map[s[i]] = i;
            max_count = max(max_count, i - l + 1);
        }

        return max_count;
    }
};
