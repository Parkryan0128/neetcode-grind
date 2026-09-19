class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        std::stack<pair<int,int>> my_stack;
        std::vector<int> res(temperatures.size());

        for (int i=0; i<temperatures.size(); i++) {
            int t = temperatures[i];
            while (!my_stack.empty() && t > my_stack.top().first) {
                pair<int,int> item = my_stack.top();
                res[item.second] = i - item.second;
                my_stack.pop();
            }
            my_stack.push({t,i});
        }

        return res;
    }
};
