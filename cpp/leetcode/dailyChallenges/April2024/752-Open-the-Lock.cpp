/*

https://leetcode.com/problems/open-the-lock/description/

*/

#include<string>
#include<vector>
#include<queue>
#include<unordered_map>

using namespace std;

class Solution {

    vector<string> genPos(string& pos) {
        vector<string> nextPos;

        for(int i = 0; i < pos.size(); i++) {
            string tempPos = pos;
            int curr = pos[i]-'0';

            char next = '0' + (curr+1)%10;
            char prev = '0' + (curr+9)%10;

            tempPos[i] = next;
            nextPos.push_back(tempPos);
            tempPos[i] = prev;
            nextPos.push_back(tempPos);
        }

        return nextPos;
    }

public:
    int openLock(vector<string>& deadends, string target) {
        
        unordered_map<string, bool> deadendMap;
        unordered_map<string, bool> seen;

        for(auto& deadend: deadends) {
            deadendMap[deadend] = true;
        }

        string start = "0000";

        if(deadendMap[start]) {
            return -1;
        }

        queue<pair<string, int>> q;
        q.push({start, 0});
        seen[start] = true;

        while(!q.empty()) {
            pair<string, int> p = q.front();
            q.pop();

            if(p.first == target) {
                return p.second;
            }

            vector<string> nextPos = genPos(p.first);

            for(auto& pos : nextPos) {
                if(!seen[pos] && !deadendMap[pos]) {
                    seen[pos] = true;
                    q.push({pos, p.second+1});
                }
            }
        }

        return -1;
    }
};

int main() {
    return 0;
}