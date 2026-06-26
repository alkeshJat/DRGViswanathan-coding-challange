//leetcode 6
//zigzag version

class Solution {
public:
    string convert(string s, int numRows) {
        if (numRows == 1 || numRows >= s.size())
            return s;

        vector<string> rows(numRows);

        int currRow = 0;
        bool goingDown = false;

        for (char c : s) {
            rows[currRow] += c;

            if (currRow == 0 || currRow == numRows - 1)
                goingDown = !goingDown;

            currRow += goingDown ? 1 : -1;
        }

        string ans;
        for (string &row : rows)
            ans += row;

        return ans;
    }
};

//leetcode 
//valid sudoku
class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        unordered_set<string> seen;

        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                if (board[i][j] == '.') continue;

                string row = "row" + to_string(i) + board[i][j];
                string col = "col" + to_string(j) + board[i][j];
                string box = "box" + to_string(i / 3) + to_string(j / 3) + board[i][j];

                if (seen.count(row) || seen.count(col) || seen.count(box))
                    return false;

                seen.insert(row);
                seen.insert(col);
                seen.insert(box);
            }
        }

        return true;
    }
};
