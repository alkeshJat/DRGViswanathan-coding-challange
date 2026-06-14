//8. String to Integer (atoi)


class Solution {
public:
    bool isDigit(char c) { return c >= '0' && c <= '9'; }

public:
    int myAtoi(string s) {
        //"    123" => 123
        //"    -123" => -123
        //"    +123" => 123
        // "    -23ab2" => -23

        // removing spaces
        long long num = 0;
        int i = 0;
        while (i < s.size() && s[i] == ' ') {
            i = i + 1;
        }
        // signedness
        //"    -23" => -23
        int sign = 1;
        if (i < s.size()) {
            if (s[i] == '-') {
                sign = -1;
                i = i + 1;
            } else if (s[i] == '+') {
                i = i + 1;
            }
        }

        // conversion
        //  INT_MAX = 2147483647
        //  INT_MIN = -2147483648
        while (i < s.size() && isDigit(s[i])) {
            int digit = s[i] - '0';

            if (num == INT_MAX / 10) {
                if (sign == 1) {
                    if (s[i]-'0' > 7) {
                        return INT_MAX;
                    }
                } else {
                    if (s[i]-'0' > 8) {
                        return INT_MIN;
                    }
                }
            }
            if (num > INT_MAX / 10 || (num == INT_MAX / 10 && digit > 7)) {

                if (sign == 1) {
                    return INT_MAX;
                } else {
                    return INT_MIN;
                }
            }

            num = num * 10 + digit;
            i = i + 1;
        }

        return num * sign;
    }
};




// 13. Roman To Integer




class Solution {
public:
    int romanToInt(string s) {
        unordered_map<char, int> mpp;

        mpp['I'] = 1;
        mpp['V'] = 5;
        mpp['X'] = 10;
        mpp['L'] = 50;
        mpp['C'] = 100;
        mpp['D'] = 500;
        mpp['M'] = 1000;

        int ans = 0;

        for (int i = 0; i < s.size(); i++) {

            // Check next character exists
            if (i + 1 < s.size() && mpp[s[i]] < mpp[s[i + 1]]) {
                ans = ans - mpp[s[i]];
            } else {
                ans = ans + mpp[s[i]];
            }
        }

        return ans;
    }
};