class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        vector<int> my_stack;
        for (int i=0; i<asteroids.size(); i++) {
            while (!my_stack.empty() && asteroids[i] < 0 && my_stack.back() > 0) {
                int diff = asteroids[i] + my_stack.back();
                if (diff < 0) {
                    my_stack.pop_back();
                } else if (diff > 0) {
                    asteroids[i] = 0;
                } else {
                    asteroids[i] = 0;
                    my_stack.pop_back();
                }
            }

            if (asteroids[i] != 0) {
                my_stack.push_back(asteroids[i]);
            }
        }


        return my_stack;

    }
};