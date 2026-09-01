#include <stack>

using namespace std;

class MinStack {
public:
    stack<int> s;
    stack<int> min_s;

    MinStack() {}

    void push(int value) {
        s.push(value);

        if (min_s.empty()) {
            min_s.push(value);
        } else {
            int x = min_s.top();
            if (value < x)
                min_s.push(value);
            else
                min_s.push(x);
        }
    }

    void pop() {
        s.pop();
        min_s.pop();
    }

    int top() { return s.top(); }

    int getMin() { return min_s.top(); }
};
