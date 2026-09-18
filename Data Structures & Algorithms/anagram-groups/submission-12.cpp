class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        std::unordered_map<std::string, std::vector<string>> my_map;
        std::vector<vector<string>> res;

        for (int i=0; i<strs.size(); i++) {
            int arr[26] = {0};
            for (int j=0; j< strs[i].size(); j++) {
                arr[strs[i][j] - 'a']++;
            }
            std::string key = to_string(arr[0]);
            for (int j=1; j<26; j++) {
                key += ",";
                key += to_string(arr[j]);
            }
            my_map[key].push_back(strs[i]);
        }

        for (auto& item : my_map) {
            res.push_back(item.second);
        }

        return res;
    }
};
