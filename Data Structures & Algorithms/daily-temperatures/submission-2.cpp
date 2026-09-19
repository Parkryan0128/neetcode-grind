class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        std::stack<pair<int,int>> my_stack;
        std::vector<int> res(temperatures.size(), 0);

        for (int i=0; i<temperatures.size(); i++) {
            int t = temperatures[i];
            while (!my_stack.empty() && t > my_stack.top().first) {
                auto item = my_stack.top();
                my_stack.pop();
                res[item.second] = i - item.second;
            }
            my_stack.push({t,i});
        }

        return res;
    }
};
