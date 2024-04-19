/*

https://leetcode.com/problems/number-of-islands

*/

#include<vector>
#include<queue>

using namespace std;

class Solution {
    
    int n, m;
    int di[4] = {-1, 0, 1, 0};
    int dj[4] = {0, -1, 0, 1};

public:
    void markIsland(vector<vector<char>>& grid, int i, int j) {
        queue<pair<int, int>> q;

        grid[i][j] = '0';
        q.push({i, j});

        while(!q.empty()) {
            pair<int, int> p = q.front();
            q.pop();

            for(int k = 0; k < 4; k++) {
                i = p.first + di[k];
                j = p.second + dj[k];

                if(i >= 0 && i < n && j >= 0 && j < m && grid[i][j] == '1') {
                    grid[i][j] = '0';
                    q.push({i, j});
                }
            }
        }
    }

    int numIslands(vector<vector<char>>& grid) {
        int islands = 0;
        n = grid.size();
        m = grid[0].size();

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(grid[i][j] == '1') {
                    islands++;
                    markIsland(grid, i, j);
                }
            }
        }

        return islands;
    }
};

int main() {
    return 0;
}