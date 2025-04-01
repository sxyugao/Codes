class MinStack {
  private:
    stack<int> v, mv;

  public:
    MinStack() {}

    void push(int val) {
        v.push(val);
        if (mv.empty()) {
            mv.push(val);
            return;
        }
        mv.push(min(mv.top(), val));
    }

    void pop() {
        v.pop();
        mv.pop();
    }

    int top() { return v.top(); }

    int getMin() { return mv.top(); }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */