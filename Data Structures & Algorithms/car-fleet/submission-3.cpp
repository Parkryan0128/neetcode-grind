class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        std::vector<pair<int,int>> pairs;

        for (int i=0; i<position.size(); i++) {
            pairs.push_back({position[i], speed[i]});
        }

        sort(pairs.rbegin(), pairs.rend());

        std::vector<double> my_stack;
        for (auto& item : pairs) {
            my_stack.push_back((double) (target - item.first) / item.second);
            if (my_stack.size() >= 2 && my_stack[my_stack.size()-1] <= my_stack[my_stack.size()-2]) {
                my_stack.pop_back();
            }
        }


        return my_stack.size();

    }
};
