//leetcode70
//climbing stairs

class Solution {
public:
    int climbStairs(int n) {
        if (n <= 2)
            return n;

        int prev2 = 1;
        int prev1 = 2;

        for (int i = 3; i <= n; i++) {
            int curr = prev1 + prev2;
            prev2 = prev1;
            prev1 = curr;
        }

        return prev1;
    }
};

//leetcode1172
//dinner plate stacks


class DinnerPlates {
public:
    int capacity;
    vector<stack<int>> stacks;
    set<int> pushSet; // stacks with available space
    set<int> popSet;  // non-empty stacks

    DinnerPlates(int capacity) {
        this->capacity = capacity;
    }

    void push(int val) {
        if (pushSet.empty()) {
            stacks.push_back(stack<int>());
            pushSet.insert(stacks.size() - 1);
        }

        int idx = *pushSet.begin();
        stacks[idx].push(val);

        popSet.insert(idx);

        if (stacks[idx].size() == capacity)
            pushSet.erase(idx);
    }

    int pop() {
        if (popSet.empty())
            return -1;

        int idx = *popSet.rbegin();
        return popAtStack(idx);
    }

    int popAtStack(int index) {
        if (index < 0 || index >= stacks.size() || stacks[index].empty())
            return -1;

        int val = stacks[index].top();
        stacks[index].pop();

        pushSet.insert(index);

        if (stacks[index].empty())
            popSet.erase(index);

        while (!stacks.empty() && stacks.back().empty()) {
            int last = stacks.size() - 1;
            pushSet.erase(last);
            popSet.erase(last);
            stacks.pop_back();
        }

        return val;
    }
};