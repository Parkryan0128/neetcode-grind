class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> pref = vector(nums.size(),0);
        vector<int> suff = vector(nums.size(),0);
        vector<int> res = vector(nums.size(),0);


        pref[0] = 1;
        suff[nums.size()-1] = 1;

        for (int i=1; i < pref.size(); i++) {
            pref[i] = nums[i-1] * pref[i-1];
        }


        for (int i=suff.size()-2; i >= 0; i--) {
            suff[i] = nums[i+1] * suff[i+1];
        }

        for (int i=0; i< res.size(); i++) {
            res[i] = pref[i] * suff[i];
        }

        return res;
    }
};
