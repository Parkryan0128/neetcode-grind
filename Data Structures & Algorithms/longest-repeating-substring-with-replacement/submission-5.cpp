class Solution {
public:
    int characterReplacement(string s, int k) {
        std::unordered_map<char,int> my_map;
        int maxf = 0;
        int max_length = 0;
        int l = 0;

        for (int i=0; i < s.size(); i++) {
            my_map[s[i]]++;
            maxf = max(maxf, my_map[s[i]]);

            while (i - l + 1 > (maxf + k)) {
                my_map[s[l]]--;
                l++;
            }

            max_length = max(max_length, i - l + 1);
        }

        return max_length;
    }
};
