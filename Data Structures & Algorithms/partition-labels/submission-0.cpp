class Solution {
public:
    vector<int> partitionLabels(string s) {
        std::unordered_map<char,int> my_map;

        for (int i=0; i<s.size(); i++) {
            my_map[s[i]] = i;
        }


        vector<int> res;
        int max_index = my_map[s[0]];
        int count = 0;
        for (int i =0; i<s.size(); i++) {
            char c = s[i];
            count++;
            max_index = max(max_index, my_map[c]);
            if (max_index == i) {
                res.push_back(count);
                count = 0;
            }
        }

        return res;
    }
};
