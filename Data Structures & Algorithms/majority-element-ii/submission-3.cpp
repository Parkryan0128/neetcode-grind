class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int candidate1 = 0;
        int candidate2 = 0;
        int count1 = 0;
        int count2 = 0;
        int n = nums.size();

        for (int i=0; i< nums.size(); i++) {
            if (nums[i] == candidate1) {
                count1++;
            } else if (nums[i] == candidate2) {
                count2++;
            } else if (count1 == 0) {
                count1 = 1;
                candidate1 = nums[i];
            } else if (count2 == 0) {
                count2 = 1;
                candidate2 = nums[i];
            } else {
                count1--;
                count2--;
            }
        }
        std::cout << candidate1 << std::endl;
        std::cout << candidate2 << std::endl;
        count1 = 0;
        count2 = 0;

        for (int i=0; i<nums.size(); i++) {
            if (nums[i] == candidate1) {
                count1++;
            }

            if (nums[i] == candidate2) {
                count2++;
            }
        }


        std::vector<int> res;

        if (count1 > n/3) res.push_back(candidate1);
        if (count2 > n/3) res.push_back(candidate2);

        return res;
    }
};