class Solution {
public:
    int calPoints(vector<string>& operations) {
        std::stack<int> my_stack;
        
        for (int i=0; i<operations.size(); i++) {
            if (operations[i] == "C") {
                my_stack.pop();
            } else if (operations[i] == "D") {
                int temp = my_stack.top();
                my_stack.push(temp * 2);
            } else if (operations[i] == "+") {
                int temp = my_stack.top();
                my_stack.pop();
                int temp2 = my_stack.top() + temp;

                my_stack.push(temp);
                my_stack.push(temp2);

            } else {
                my_stack.push(stoi(operations[i]));
            }
        }
        int score = 0;
        while (!my_stack.empty()) {
            score += my_stack.top();
            my_stack.pop();
        }


        return score;
    }
};