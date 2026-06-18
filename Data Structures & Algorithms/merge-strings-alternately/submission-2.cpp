class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        int n = std::min(word1.size(), word2.size());
        string s = "";

        for (int i=0; i<n; i++) {
            s += word1[i];
            s += word2[i];
        }


        s += word1.substr(n);
        s += word2.substr(n);

        return s;
    }
};