class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string,vector<string>> my_map;

        for (int i=0; i<strs.size(); i++) {
            int arr[26] = { 0 };

            for (int j=0; j< strs[i].size(); j++) {
                arr[strs[i][j] - 'a']++;
            }

            string key = "";
            for (int j=0; j<26; j++) {
                key += '#' + to_string(arr[j]);
            }

            my_map[key].push_back(strs[i]);
        }
        vector<vector<string>> res;

        for (auto& item : my_map) {
            res.push_back(item.second);
        }

        return res;
    }
};
