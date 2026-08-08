class MinStack {
public:
    std::stack<int> min_stack;
    std::stack<int> my_stack;

    MinStack() {}
    
    void push(int val) {
        my_stack.push(val);
        int min_val = min(val, min_stack.empty() ? val : min_stack.top());
        min_stack.push(min_val);
    }
    
    void pop() {
        my_stack.pop();
        min_stack.pop();
    }
    
    int top() {
        return my_stack.top();
    }
    
    int getMin() {
        return min_stack.top();
    }
};
