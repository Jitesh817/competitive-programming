/*

https://leetcode.com/problems/number-of-wonderful-substrings

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
    long long wonderfulSubstrings(string word) {
        unordered_map<int, int> freq;
        long long result = 0;
        int prefixXor = 0;
        freq[prefixXor] = 1;

        for(char& c: word) {
            prefixXor ^= (1<<(c-'a'));
            result += freq[prefixXor];
            freq[prefixXor]++;

            for(int i = 0; i < 10; i++) {
                result += freq[prefixXor^(1<<i)];
            }
        }

        return result;
    }
};

int main() {
    return 0;
}