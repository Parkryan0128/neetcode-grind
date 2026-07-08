class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        std::vector<int> res(temperatures.size(), 0);

        std::stack<pair<int,int>> my_stack;

        for (int i=0; i < temperatures.size(); i++) {
            int t = temperatures[i];
            while (!my_stack.empty() && t > my_stack.top().first) {
                auto temp = my_stack.top();
                my_stack.pop();
                res[temp.second] = i - temp.second;
            }

            my_stack.push({t,i});
        }

        return res;
    }
};
