/*

https://leetcode.com/problems/minimum-number-of-operations-to-make-array-xor-equal-to-k

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
    int minOperations(vector<int>& nums, int k) {

        int arrayXor = 0;
        for(int& num: nums) {
            arrayXor ^= num;
        }

        int ops = 0;
        while(k > 0 || arrayXor > 0) {
            if((k&1)^(arrayXor&1)) {
                ops++;
            }
            k = k>>1;
            arrayXor = arrayXor>>1;
        }

        return ops;
    }
};

int main() {
    return 0;
}