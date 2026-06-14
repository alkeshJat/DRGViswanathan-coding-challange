//1318. Minimum Flips to Make a OR b Equal to c



class Solution {
public:
    int minFlips(int a, int b, int c) {
        int result = ((a|b)^c);

        int result1 = (a&b);

        int result2 = result&result1;
        return __builtin_popcount(result)+__builtin_popcount(result2);
    }
};


//2864. Maximum Odd Binary Number

class Solution {
public:
    string maximumOddBinaryNumber(string s) {
        int n = s.size();
        int start = 0;
        int end = n - 1;
        while (start <= end) {
            if (s[start] == '1') {
                start++;
            }
            if (s[end] == '0') {
                end--;
            }
            if (start <= end && (s[start] == '0' && s[end] == '1')) {
                swap(s[start], s[end]);
                start++;
                end--;
            }
        }
        swap(s[start - 1], s[n - 1]);
        return s;
    }
};