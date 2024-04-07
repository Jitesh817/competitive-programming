/*

https://leetcode.com/problems/valid-parenthesis-string/description/

*/
#include<string>

using namespace std;

class Solution {
public:
    bool validStringHelper(int open, int index, string& s, vector<vector<int>> &dp) {

        if(index >= s.size()) {
            return open == 0;
        }

        if(dp[open][index] != -1) {
            return dp[open][index];
        }

        if(s[index] == '(') {
            return dp[open][index] = validStringHelper(open+1, index+1, s, dp);
        } else if (s[index] == ')') {
            if(open == 0) {
                return false;
            }
            return dp[open][index] = validStringHelper(open-1, index+1, s, dp);
        } else {
            bool valid = open > 0 ? validStringHelper(open-1, index+1, s, dp) : false;
            valid = valid || validStringHelper(open, index+1, s, dp) || validStringHelper(open+1, index+1, s, dp);
            return dp[open][index] = valid;
        }

    }

    bool checkValidString(string s) {
        vector<vector<int>> dp(101, vector<int>(101, -1));
        return validStringHelper(0, 0, s, dp);
    }
};

int main() {
    return 0;
}