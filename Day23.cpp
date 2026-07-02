// 455. Assign Cookies

class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        int cookiesNums = s.size();
        if (cookiesNums == 0) return 0;

        sort(g.begin(), g.end());
        sort(s.begin(), s.end());

        int maxNum = 0;
        int cookieIndex = cookiesNums - 1;
        int childIndex = g.size() - 1;

        while (cookieIndex >= 0 && childIndex >= 0) {
            if (s[cookieIndex] >= g[childIndex]) {
                maxNum++;
                cookieIndex--;
                childIndex--;
            } else {
                childIndex--;
            }
        }

        return maxNum;
    }
};

//561. Array partition


class Solution {
public:
    int arrayPairSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        int sum = 0;
        for (int i = 0; i < nums.size(); i += 2) {
            sum += nums[i];
        }

        return sum;
    }
};