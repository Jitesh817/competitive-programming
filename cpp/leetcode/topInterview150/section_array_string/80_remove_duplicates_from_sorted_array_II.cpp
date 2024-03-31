/*

https://leetcode.com/problems/remove-element

*/


#include<vector>

using namespace std;

class Solution {
public:
    //approach
    int removeDuplicates(vector<int>& nums) {
        
        unordered_map<int, int> freqMap;

        int i = 0, j = 0;

        while(j < nums.size()) {
            freqMap[nums[j]]++;
            if(freqMap[nums[j]] <= 2) {
                nums[i] = nums[j];
                i++;
            }
            j++;
        }

        return i;
    }

    //approach2
    int removeDuplicatesII(vector<int>& nums) {
        
        int i = 1, j = 1;

        while(j < nums.size()) {
            if(i == 1 || nums[j] != nums[i-2]) {
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