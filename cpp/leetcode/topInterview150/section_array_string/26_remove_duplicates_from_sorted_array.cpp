/*

https://leetcode.com/problems/remove-element

*/


#include<vector>

using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        
        int i = 1, j = 1;

        while(j < nums.size()) {
            if(nums[j] != nums[j-1]) {
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