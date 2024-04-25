/*

https://leetcode.com/problems/longest-ideal-subsequence/

*/

#include<string>
#include<vector>

using namespace std;

class Solution {
public:
    int longestIdealString(string s, int k) {
        
        vector<int> dp(26, 0);

        for(int i = 0; i < s.length(); i++) {
            int index = s[i]-'a';

            int left = max(0, index - k);
            int right = min(25, index + k);

            int maxLen = 0;
            for(int j = left; j <= right; j++) {
                maxLen = maxLen < dp[j] ? dp[j] : maxLen;
            }
            dp[index] = maxLen + 1;
        }
        
        return *max_element(dp.begin(), dp.end());
    }
};

int main() {
    return 0;
}