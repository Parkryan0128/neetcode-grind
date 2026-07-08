class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        std::stack<int> my_stack;
        for (int i=0; i<tokens.size(); i++) {
            if (tokens[i] == "+") {
                int temp = my_stack.top();
                my_stack.pop();
                int temp2 = my_stack.top();
                my_stack.pop();

                my_stack.push(temp + temp2);
            } else if (tokens[i] == "-") {
                int temp = my_stack.top();
                my_stack.pop();
                int temp2 = my_stack.top();
                my_stack.pop();

                my_stack.push(temp2 - temp);
            } else if (tokens[i] == "*") {
                int temp = my_stack.top();
                my_stack.pop();
                int temp2 = my_stack.top();
                my_stack.pop();

                my_stack.push(temp * temp2);
            } else if (tokens[i] == "/") {
                int temp = my_stack.top();
                my_stack.pop();
                int temp2 = my_stack.top();
                my_stack.pop();

                my_stack.push(temp2 / temp);
            } else {
                my_stack.push(stoi(tokens[i]));
            }
        }

        return my_stack.top();
    }
};
