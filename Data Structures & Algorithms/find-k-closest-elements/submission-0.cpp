class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int left = 0;
        int right = arr.size() - 1;


        while (right - left + 1 > k) {
            if (abs(arr[left]-x) > abs(arr[right] -x)) {
                left++;
            } else {
                right--;
            }
        }

        vector<int> res;

        for (int i = left; i < right+1; i++) {
            res.push_back(arr[i]);
        }

        return res;
    }
};