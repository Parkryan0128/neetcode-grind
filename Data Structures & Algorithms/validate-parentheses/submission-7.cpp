class Solution {
public:
    bool isValid(string s) {

        std::stack<char> my_stack;

        for (int i=0; i<s.size(); i++) {
            if (s[i] == ')') {
                if (my_stack.empty() || my_stack.top() != '(') return false;
                my_stack.pop();
            } else if (s[i] == ']') {
                if (my_stack.empty() || my_stack.top() != '[') return false;
                my_stack.pop();
            } else if (s[i] == '}') {
                if (my_stack.empty() || my_stack.top() != '{') return false;
                my_stack.pop();
            } else {
                my_stack.push(s[i]);
            }

        }

        return my_stack.size() == 0;
    }
};
