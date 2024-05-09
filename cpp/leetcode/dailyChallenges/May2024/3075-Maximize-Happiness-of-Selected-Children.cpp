/*

https://leetcode.com/problems/maximize-happiness-of-selected-children/

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
public:
    long long maximumHappinessSum(vector<int>& happiness, int k) {
        long long maxHapiness = 0;
        int n = happiness.size();

        sort(happiness.begin(), happiness.end());
        for(int i = n-1; i >= n-k; i--) {
            maxHapiness += max(0, happiness[i] + i - n + 1);
        }

        return maxHapiness;
    }
};

int main() {
    return 0;
}