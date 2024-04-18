/*

https://leetcode.com/problems/island-perimeter/

*/

#include<vector>
#include<queue>

using namespace std;

class Solution {
    int di[4] = {0,-1,0,1};
    int dj[4] = {-1,0,1,0};

    void traverseGrid(vector<vector<int>>& grid, int si, int sj, int& perimeter) {
        queue<pair<int, int>> q;
        q.push({si, sj});
        grid[si][sj] = -1;

        while(!q.empty()) {
            pair<int, int> p = q.front();
            q.pop();

            for(int k = 0; k < 4; k++) {
                int i = p.first + di[k];
                int j = p.second + dj[k];

                if(i >= 0 && i < grid.size() && j >= 0 && j < grid[i].size()) {
                    if(grid[i][j] == 1) {
                        grid[i][j] = -1;
                        q.push({i,j});
                    } else if (grid[i][j] == 0) {
                        perimeter++;
                    }
                } else {
                    perimeter++;
                }
            }
        }
    }

public:
    int islandPerimeter(vector<vector<int>>& grid) {
        
        int perimeter = 0;
        bool done = false;
        for(int i = 0; i < grid.size(); i++) {
            for(int j = 0; j < grid[i].size(); j++) {
                if(grid[i][j]) {
                    traverseGrid(grid, i, j, perimeter);
                    done = true;
                    break;
                }
            }
            if(done) {
                break;
            }
        }

        return perimeter;
    }
};

int main() {
    return 0;
}