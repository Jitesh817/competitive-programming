/*

https://leetcode.com/problems/score-after-flipping-matrix/

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
    int n, m;

    void flipRow(vector<int>& row) {
        for(auto& el: row) {
            el ^= 1;
        }
    }

    void flipColumn(vector<vector<int>>& grid, int j) {
        for(int i = 0; i < n; i++) {
            grid[i][j] ^= 1;
        }
    }

public:
    int matrixScore(vector<vector<int>>& grid) {

        n = grid.size();
        m = grid[n-1].size();

        for(int i = 0; i < n; i++) {
            if(grid[i][0] == 0) {
                flipRow(grid[i]);
            }
        }

        for(int j = 0; j < m; j++) {
            int zeroCount = 0;
            for(int i = 0; i < n; i++) {
                if(grid[i][j] == 0) {
                    zeroCount++;
                }
            }

            if(2*zeroCount > n) {
                flipColumn(grid, j);
            }
        }

        int sum = 0;

        for(auto& row: grid) {
            int num = 0;
            for(auto&el: row) {
                num = 2*num + el;
            }
            sum += num;
        }

        return sum;
    }
};

int main() {
    return 0;
}