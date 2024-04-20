/*

https://leetcode.com/problems/find-all-groups-of-farmland/

*/

#include<vector>
#include<queue>

using namespace std;

class Solution {
    
    int n, m;
    int di[4] = {-1, 0, 1, 0};
    int dj[4] = {0, -1, 0, 1};
    
    void traverseFarmland(vector<vector<int>>& land, int i, int j, vector<int>& coordinate) {
        
        queue<pair<int, int>> q;
        q.push({i,j});
        land[i][j] = 0;

        while(!q.empty()) {
            pair<int, int> p = q.front();
            q.pop();

            for(int k = 0; k < 4; k++) {
                i = p.first + di[k];
                j = p.second + dj[k];

                if(i >= 0 && i < n && j >= 0 && j < m && land[i][j]) {
                    land[i][j] = 0;
                    if(coordinate[2] <= i && coordinate[3] <= j) {
                        coordinate[2] = i; 
                        coordinate[3] = j;
                    }
                    q.push({i,j});
                }
            }
        }
    }

public:
    vector<vector<int>> findFarmland(vector<vector<int>>& land) {
        
        n = land.size();
        m = land[0].size();
        vector<vector<int>> coordinates;
        
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(land[i][j]) {
                    vector<int> coordinate(4);
                    coordinate[0] = coordinate[2] = i;
                    coordinate[1] = coordinate[3] = j;

                    traverseFarmland(land, i, j, coordinate);
                    coordinates.push_back(coordinate);
                }
            }
        }

        return coordinates;
    }
};

int main() {
    return 0;
}