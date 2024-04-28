/*

https://leetcode.com/problems/minimum-falling-path-sum-ii/

*/

#include<vector>

using namespace std;

class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& grid) {
        
        int n = grid.size();
        for(int i = 1; i < n; i++) {
            for(int j = 0; j < n; j++) {
                
                int min = INT_MAX;
                for(int k = 0; k < n; k++) {
                    if(k == j) {
                        continue;
                    }
                    min = min < grid[i-1][k] ? min : grid[i-1][k];
                }

                grid[i][j] += min;
            }
        }

        return *min_element(grid.back().begin(), grid.back().end());
    }
};

class SolutionOptimized {
public:
    int minFallingPathSum(vector<vector<int>>& grid) {
        
        int n = grid.size();
        for(int i = 1; i < n; i++) {

            int min1 = INT_MAX, ind1 = -1, min2 = INT_MAX, ind2 = -1;

            for(int j = 0; j < n; j++) {
                if(grid[i-1][j] < min1) {
                    min2 = min1;
                    ind2 = ind1;
                    min1 = grid[i-1][j];
                    ind1 = j;
                } else if(grid[i-1][j] < min2) {
                    min2 = grid[i-1][j];
                    ind2 = j;
                }
            }

            for(int j = 0; j < n; j++) {
                if(j == ind1) {
                    grid[i][j] += min2;
                } else {
                    grid[i][j] += min1;
                }
            }
        }

        return *min_element(grid.back().begin(), grid.back().end());
    }
};

int main() {
    return 0;
}