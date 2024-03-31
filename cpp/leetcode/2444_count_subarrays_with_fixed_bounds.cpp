/*

https://leetcode.com/problems/count-subarrays-with-fixed-bounds/

*/


#include<vector>

using namespace std;

class Solution {
public:
    long long countSubarrays(vector<int>& nums, int minK, int maxK) {

        long long count = 0;
        long long outOfBoundIndex = -1;
        long long latestMinIndex = -1;
        long long latestMaxIndex = -1;

        for(int i = 0; i < nums.size(); i++) {

            if(!(minK <= nums[i] && nums[i] <= maxK)) {
                outOfBoundIndex = i;
            }  
            
            if(nums[i] == minK) {
                latestMinIndex = i;
            }

            if (nums[i] == maxK) {
                latestMaxIndex = i;
            }

            count += max(0LL, min(latestMinIndex, latestMaxIndex) - outOfBoundIndex);
        }

        return count;   
    }
};

int main() {
    return 0;
}