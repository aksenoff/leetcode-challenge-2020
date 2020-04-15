// https://leetcode.com/problems/min-stack/

#include<vector>
#include<algorithm>

using namespace std;

class MinStack {
    vector<int> s;
public:
    /** initialize your data structure here. */
    MinStack() {

    }

    void push(int x) {
        s.push_back(x);
    }

    void pop() {
        s.pop_back();
    }

    int top() {
        return s.back();
    }

    int getMin() {
        return *min_element(s.begin(), s.end());
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */