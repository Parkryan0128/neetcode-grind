class Solution {
public:
    bool isValid(string s) {
        std::stack<char> my_stack;
        std::unordered_map<char,char> char_map;

        char_map[']'] = '[';
        char_map['}'] = '{';
        char_map[')'] = '(';


        for (int i=0; i<s.size(); i++) {
            if (s[i] == '(' || s[i] == '[' || s[i] == '{') {
                my_stack.push(s[i]);
            } else {
                if (my_stack.size() > 0) {
                    char item = my_stack.top();
                    if (char_map[s[i]] != item) {
                        return false;
                    }
                    my_stack.pop();
                } else {
                    return false;
                }
            }
        }

        return my_stack.size() == 0;

    }
};
