/*

https://leetcode.com/problems/word-search/description/

*/

#include<vector>
#include<string>

using namespace std;

class Solution {

    int n, m, w;
    int di[4] = {-1, 0, 1, 0};
    int dj[4] = {0, -1, 0, 1};

    bool dfs(vector<vector<char>> &board, string &word, vector<vector<bool>> &vis, int i, int j, int k) {

        if(k == w) {
            return true;
        }

        vis[i][j] = true;

        for(int t = 0; t < 4; t++) {
            int i_ = i + di[t], j_ = j + dj[t];
            if(i_ >= 0 && i_ < n && j_ >= 0 && j_ < m && !vis[i_][j_] && board[i_][j_] == word[k] && dfs(board, word, vis, i_, j_, k+1)) {
                return true;
            }
        }

        vis[i][j] = false;
        
        return false;
    }

public:
    bool exist(vector<vector<char>>& board, string word) {
        n = board.size();
        m = board[n-1].size();
        w = word.size();

        vector<vector<bool>> vis(n, vector<bool>(m, false));

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(word[0] == board[i][j] && dfs(board, word, vis, i, j, 1)) {
                    return true;
                }
            }
        }

        return false;
    }
};

int main() {
    return 0;
}