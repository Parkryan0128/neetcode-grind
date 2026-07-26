class Solution {
public:
    int majorityElement(vector<int>& nums) {
        
        int count = 1;
        int curr = nums[0];
        for (int i=1; i<nums.size(); i++) {
            if (nums[i] != curr) {
                count--;
            } else {
                count++;
            }

            if (count == 0) {
                curr = nums[i];
                count++;
            }
        }

        return curr;
    }
};