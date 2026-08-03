class Solution {
public:
    int maxTurbulenceSize(vector<int>& arr) {
        int n = arr.size();
        int count = 0;
        int res = 0;
        int sign = -1;

        for (int i = 0; i < arr.size()-1; i++) {
            if (arr[i] > arr[i+1]) {
                if (sign == 0) {
                    count++;
                } else {
                    count = 1;
                }
                sign = 1;
            } else if (arr[i] < arr[i+1]) {
                if (sign == 1) {
                    count++;
                } else {
                    count = 1;
                }
                sign = 0;
            } else {
                count = 0;
                sign = -1;
            }

            res = max(res,count);
        }

        return res + 1;
    }
};