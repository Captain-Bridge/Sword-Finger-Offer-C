#include <stack>
class Solution {
  public:
    void push(int x) {
        data.push(x);
        if (mins.empty() || x <= mins.top()) {
            mins.push(x);
        }
    }

    void pop() {
        if (data.empty()) return;
        if (data.top() == mins.top()) {
            mins.pop();
        }
        data.pop();
    }

    int top() {
        if (data.empty()) throw runtime_error("Stack is empty");
        return data.top();
    }

    int min() {
        if (mins.empty()) throw runtime_error("Stack is empty");
        return mins.top();
    }

  private:
    stack<int> data; // 数据栈
    stack<int> mins; // 最小值栈
};