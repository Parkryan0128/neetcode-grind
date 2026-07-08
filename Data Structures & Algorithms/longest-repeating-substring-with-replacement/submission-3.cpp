class Solution {
public:
    int characterReplacement(string s, int k) {
        std::unordered_map<char,int> my_map;
        int l = 0;
        int maxf = 0;
        int res = 0;

        for (int r = 0; r < s.size(); r++) {
            my_map[s[r]]++;
            maxf = std::max(maxf, my_map[s[r]]);

            while (r - l + 1 - maxf > k) {
                my_map[s[l]]--;
                l++;
            }

            res = std::max(res, r-l+1);
        }

        return res;

    }
};
