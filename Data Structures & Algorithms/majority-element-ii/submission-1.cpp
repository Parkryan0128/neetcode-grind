class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int threshold = nums.size() / 3;
        
        unordered_map<int,int> my_map;
        vector<vector<int>> freq(nums.size()+1);
        vector<int> res;



        for (int i=0; i<nums.size(); i++) {
            my_map[nums[i]]++;
        }

        for (auto & [key, value] : my_map) {
            freq[value].push_back(key);
        }

        for (int i=freq.size()-1; i > threshold; i--) {
            for (int item : freq[i]) {
                res.push_back(item);
            }
        }

        return res;

    }
};