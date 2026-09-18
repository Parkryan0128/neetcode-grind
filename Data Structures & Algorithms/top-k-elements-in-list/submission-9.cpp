class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        std::unordered_map<int,int> my_map;

        for (int i=0; i<nums.size(); i++) {
            my_map[nums[i]]++;
        }

        std::vector<std::vector<int>> bucket(nums.size()+1);

        for (auto& item : my_map) {
            bucket[item.second].push_back(item.first);
        }

        int count = 0;
        std::vector<int> res;

        for (int i = bucket.size()-1; i >= 0; i--) {
            for (int j=0; j < bucket[i].size(); j++) {
                if (count < k) {
                    res.push_back(bucket[i][j]);
                    count++;
                } else {
                    break;
                }
            }
        }

        return res;
    }
};
