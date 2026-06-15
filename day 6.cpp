//leetcode 907
//Sum of Subarray Minimums

class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        int n = arr.size();
        const int MOD = 1e9 + 7;

        vector<int> left(n), right(n);
        stack<int> st;
        
        for (int i = 0; i < n; i++) {
            while (!st.empty() && arr[st.top()] > arr[i]) {
                st.pop();
            }
            left[i] = st.empty() ? i + 1 : i - st.top();
            st.push(i);
        }

        while (!st.empty()) st.pop();
        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && arr[st.top()] >= arr[i]) {
                st.pop();
            }
            right[i] = st.empty() ? n - i : st.top() - i;
            st.push(i);
        }

        long long ans = 0;

        for (int i = 0; i < n; i++) {
            ans = (ans + (long long)arr[i] * left[i] * right[i]) % MOD;
        }
        return (int)ans;
    }
};

//leetcode 496
//Next Greater Element

class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        vector<int> ans;
        for (int x : nums1) {
            int idx = -1;

            for (int i = 0; i < nums2.size(); i++) {
                if (nums2[i] == x) {
                    idx = i;
                    break;
                }
            }
            int nextGreater = -1;
            for (int i = idx + 1; i < nums2.size(); i++) {
                if (nums2[i] > x) {
                    nextGreater = nums2[i];
                    break;
                }
            }
            ans.push_back(nextGreater);
        }

        return ans;
    }
};