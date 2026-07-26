class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        sort(strs.begin(), strs.end());
        string first = strs[0];
        string second = strs[strs.size()-1];

        int n = min(first.size(),second.size());
        string res = "";

        for (int i=0; i<n; i++) {
            if (first[i] == second[i]) {
                res += first[i];
            } else {
                break;
            }
        }

        return res;


    }
};