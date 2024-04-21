/*

https://leetcode.com/problems/jump-game-ii

*/

#include<vector>

using namespace std;

class Solution {
public:
    int jump(vector<int>& nums) {

        if(nums.size() < 2) {
            return 0;
        }

        int jumps = 1;
        int maxReach = nums[0];
        int stepsLeft = nums[0];
        for(int i = 1; i < nums.size()-1; i++) {
            maxReach = max(maxReach, i + nums[i]);
            stepsLeft--;

            if(stepsLeft == 0) {
                jumps++;
                stepsLeft = maxReach-i;
            }
        }

        return jumps;
    }
};

int main() {
    return 0;
}