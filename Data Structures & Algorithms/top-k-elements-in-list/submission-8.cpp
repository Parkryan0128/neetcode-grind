class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        std::unordered_map<int,int> my_map;

        for (int i=0; i<nums.size(); i++) {
            my_map[nums[i]]++;
        }

        std::priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;

        for (auto& item : my_map) {
            pq.push({item.second, item.first});
            if (pq.size() > k) {
                pq.pop();
            }
        }

        vector<int> res;

        while(!pq.empty()) {
            res.push_back(pq.top().second);
            pq.pop();
        }

        return res;
    }
};
