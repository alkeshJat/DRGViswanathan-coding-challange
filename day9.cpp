//leetcode 1381
//design a stack with implement operations

class CustomStack {
private:
    int maxSize;
    vector<int> st;
    vector<int> inc;

public:
    CustomStack(int maxSize) {
        this->maxSize = maxSize;
    }

    void push(int x) {
        if (st.size() == maxSize) return;

        st.push_back(x);
        inc.push_back(0);
    }

    int pop() {
        if (st.empty()) return -1;

        int i = st.size() - 1;
        int res = st[i] + inc[i];

        if (i > 0)
            inc[i - 1] += inc[i];

        st.pop_back();
        inc.pop_back();

        return res;
    }

    void increment(int k, int val) {
        int i = min(k, (int)st.size()) - 1;

        if (i >= 0)
            inc[i] += val;
    }
};

//leetcode 155
//Min stack

class MinStack {
private:
    stack<int> st;
    stack<int> minSt;

public:
    MinStack() {}

    void push(int val) {
        st.push(val);

        if (minSt.empty())
            minSt.push(val);
        else
            minSt.push(min(val, minSt.top()));
    }

    void pop() {
        st.pop();
        minSt.pop();
    }

    int top() { return st.top(); }

    int getMin() { return minSt.top(); }
};