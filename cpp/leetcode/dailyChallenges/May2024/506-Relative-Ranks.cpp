/*

https://leetcode.com/problems/relative-ranks/

*/

#include <algorithm>
#include <bitset>
#include <complex>
#include <deque>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <tuple>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>

using namespace std;

class Solution {

    static bool compare(pair<int, int>& p1, pair<int, int>& p2) {
        return p1.first > p2.first;
    }

public:
    vector<string> findRelativeRanks(vector<int>& score) {
        vector<pair<int, int>> scoreIndexPair(score.size());

        for(int i = 0; i < score.size(); i++) {
            scoreIndexPair[i] = {score[i], i};
        }

        sort(scoreIndexPair.begin(), scoreIndexPair.end(), compare);

        vector<string> ranks(score.size());

        for(int i = 0; i < score.size(); i++) {
            int index = scoreIndexPair[i].second;
            switch(i) {
                case 0:
                    ranks[index] = "Gold Medal";
                    break;
                case 1:
                    ranks[index] = "Silver Medal";
                    break;
                case 2:
                    ranks[index] = "Bronze Medal";
                    break;
                default:
                    ranks[index] = to_string(i+1);
            }
        }

        return ranks;
    }
};

int main() {
    return 0;
}