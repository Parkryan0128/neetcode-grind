class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        int i = 0;
        int n = std::min(word1.size(), word2.size());
        std::string ans = "";
        while (i < n) {
            ans += word1[i];
            ans += word2[i];
            i++;
        }

        if (word1.size() == n) {
            ans += word2.substr(i);
        } else {
            ans += word1.substr(i);
        }

        return ans;
    }
};