#include <stack>
class Solution
{
public:
    void push(int node) {
       stack1.push(node);
    }

    int pop() {
        int front;
        if (!stack1.empty()) {
            while(!stack1.empty()){
                int curr = stack1.top();
                stack2.push(curr);
                stack1.pop();
            }
            front = stack2.top();
            stack2.pop();
            while(!stack2.empty()){
                int curr = stack2.top();
                stack1.push(curr);
                stack2.pop();
            }
        }
        return front;
    }

private:
    stack<int> stack1;
    stack<int> stack2;
};