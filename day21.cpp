//leetcode 38
//count and say
class Solution {
public:
    string countAndSay(int n) {
        string ans = "1";

        for (int i = 2; i <= n; i++) {
            string temp = "";

            for (int j = 0; j < ans.size(); ) {
                int cnt = 1;

                while (j + 1 < ans.size() && ans[j] == ans[j + 1]) {
                    cnt++;
                    j++;
                }

                temp += to_string(cnt);
                temp += ans[j];
                j++;
            }

            ans = temp;
        }

        return ans;
    }
};


//leetcode 45
//jump game

class Solution {
public:
    int jump(vector<int>& nums) {
        int jumps = 0;
        int currEnd = 0;
        int farthest = 0;

        for (int i = 0; i < nums.size() - 1; i++) {
            farthest = max(farthest, i + nums[i]);

            if (i == currEnd) {
                jumps++;
                currEnd = farthest;
            }
        }

        return jumps;
    }
};