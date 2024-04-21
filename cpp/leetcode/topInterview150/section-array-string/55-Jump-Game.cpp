/*

https://leetcode.com/problems/jump-game/

*/

#include<vector>

using namespace std;

class Solution {
public:
    bool canJump(vector<int>& nums) {

        int maxReach = 0;

        for(int i = 0; i < nums.size()-1; i++) {
            maxReach = max(maxReach, i + nums[i]);

            if(maxReach == i) {
                return false;
            }

            if(maxReach >= nums.size()-1) {
                return true;
            }
        }

        return true;
    }
};

int main() {
    return 0;
}