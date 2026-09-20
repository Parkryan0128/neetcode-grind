class Solution {
public:
    int characterReplacement(string s, int k) {
        unordered_map<char,int> my_map;
        int l = 0;
        int maxf = 0;
        int max_len = 0;
        for (int i=0; i<s.size(); i++) {
            my_map[s[i]]++;
            maxf = max(maxf, my_map[s[i]]);

            while ((maxf + k) < (i - l + 1)) {
                my_map[s[l]]--;
                l++;
            }

            max_len = max(max_len, i - l + 1);
        }

        return max_len;
    }
};
