class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        string curr;
        backtrack(0,0,n,res,curr);
        return res;
    }

    void backtrack(int openN, int closedN, int n, vector<string>& res, string& curr) {
        if (openN == closedN && openN == n) {
            res.push_back(curr);
            return;
        }

        if (openN < n) {
            curr += '(';
            backtrack(openN+1, closedN, n, res, curr);
            curr.pop_back();
        }

        if (closedN < openN) {
            curr += ')';
            backtrack(openN, closedN+1, n, res, curr);
            curr.pop_back();
        }
    }
};
