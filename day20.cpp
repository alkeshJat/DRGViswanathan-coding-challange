//leetcode 17
//letter combinations of phone

class Solution {
public:
    vector<string> ans;
    vector<string> mp = {
        "", "", "abc", "def", "ghi",
        "jkl", "mno", "pqrs", "tuv", "wxyz"
    };

    void backtrack(string &digits, int idx, string &curr) {
        if (idx == digits.size()) {
            ans.push_back(curr);
            return;
        }

        string letters = mp[digits[idx] - '0'];

        for (char c : letters) {
            curr.push_back(c);
            backtrack(digits, idx + 1, curr);
            curr.pop_back();
        }
    }

    vector<string> letterCombinations(string digits) {
        if (digits.empty()) return {};

        string curr;
        backtrack(digits, 0, curr);

        return ans;
    }
};
//leetcode 43
//multiply strings
class Solution {
public:
    string multiply(string num1, string num2) {
        if (num1 == "0" || num2 == "0")
            return "0";

        int n = num1.size(), m = num2.size();
        vector<int> res(n + m, 0);

        for (int i = n - 1; i >= 0; i--) {
            for (int j = m - 1; j >= 0; j--) {
                int mul = (num1[i] - '0') * (num2[j] - '0');
                int sum = mul + res[i + j + 1];

                res[i + j + 1] = sum % 10;
                res[i + j] += sum / 10;
            }
        }

        string ans;
        int i = 0;

        while (i < res.size() && res[i] == 0)
            i++;

        while (i < res.size())
            ans += (res[i++] + '0');

        return ans;
    }
};