/*

https://leetcode.com/problems/largest-positive-integer-that-exists-with-its-negative

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
    int findMaxK(vector<int>& nums) {
        unordered_map<int, bool> M;
        int maxNum = -1;

        for(auto& num: nums) {
            if(M[-num] && abs(num) > maxNum) {
                maxNum = abs(num);
            }
            M[num] = true;
        }

        return maxNum;
    }
};

int main() {
    return 0;
}