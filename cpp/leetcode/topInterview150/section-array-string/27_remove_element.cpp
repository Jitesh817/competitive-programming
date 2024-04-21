/*

https://leetcode.com/problems/remove-element

*/


#include<vector>

using namespace std;

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int i = 0, j = 0;

        while(j < nums.size()) {
            if(nums[j] != val) {
                nums[i] = nums[j];
                i++;
            }
            j++;
        }

        return i;
    }
};

int main() {
    return 0;
}