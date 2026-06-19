//leetcode 946
//validate stack sequences

class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        stack<int> st;
        int j = 0;

        for (int x : pushed) {
            st.push(x);

            while (!st.empty() && j < popped.size() && st.top() == popped[j]) {
                st.pop();
                j++;
            }
        }

        return st.empty();
    }
};

//leetcode 1441
//Build an Array With Stack Operations

class Solution {
public:
    vector<string> buildArray(vector<int>& target, int n) {
        vector<string> ans;
        int cur = 1;

        for (int x : target) {
            while (cur < x) {
                ans.push_back("Push");
                ans.push_back("Pop");
                cur++;
            }

            ans.push_back("Push");
            cur++;
        }

        return ans;
    }
};