/*

https://leetcode.com/problems/freedom-trail/description/

*/

#include<string>
#include<vector>

using namespace std;

class Solution {

    int ringSize;
public:
    int lowestTurns(vector<vector<int>>& loc, string& key, int ringIndex, int keyIndex, vector<vector<int>> &dp) {

        if(keyIndex == key.size()) {
            return 0;
        }

        if(dp[ringIndex][keyIndex] != -1) {
            return dp[ringIndex][keyIndex];
        }

        int minTurns = INT_MAX;
        int locIndex = key[keyIndex]-'a';
        for(int i = 0; i < loc[locIndex].size(); i++) {
            minTurns = min(minTurns, 
            lowestTurns(loc, key, loc[locIndex][i], keyIndex+1, dp) 
            + min(abs(loc[locIndex][i] - ringIndex), ringSize - abs(loc[locIndex][i] - ringIndex)) + 1);
        }

        return dp[ringIndex][keyIndex] = minTurns;
    }

    int findRotateSteps(string ring, string key) {
        
        ringSize = ring.size();
        vector<vector<int>> loc(26, vector<int>());
        vector<vector<int>> dp(ringSize, vector<int>(key.size(), -1));

        for(int i = 0; i < ringSize; i++) {
            loc[ring[i]-'a'].push_back(i);
        }

        return lowestTurns(loc, key, 0, 0, dp);
    }
};