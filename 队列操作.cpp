class MyStack {
private:
    queue<int> q;

public:
    MyStack() {}

    void push(int x) {
        q.push(x);
        // 将前 size-1 个元素转移到队尾，保证队首是新元素
        int n = q.size() - 1;
        while (n--) {
            q.push(q.front());
            q.pop();
        }
    }

    int pop() {
        if (empty()) throw runtime_error("空栈");
        int val = q.front();
        q.pop();
        return val;
    }

    int top() {
        if (empty()) throw runtime_error("空栈");
        return q.front();
    }

    bool empty() {
        return q.empty();
    }
};//要自己定义真静态数组是sb