class Solution {
public:
    bool helper(string s) {
        int i = 0;
        int j = s.size() - 1;

        while (i < j) {
            if (s[i] != s[j]) {
                return false;
            }
            i++;
            j--;
        }

        return true;
    }
    bool validPalindrome(string s) {
        int i = 0;
        int j = s.size() - 1;

        while (i < j) {
            if (s[i] != s[j]) {
                string left = s.substr(i+1, j-i);
                string right = s.substr(i,j-i);
                return helper(left) || helper(right);
            }
            i++;
            j--;
        }

        return true;
    }
};