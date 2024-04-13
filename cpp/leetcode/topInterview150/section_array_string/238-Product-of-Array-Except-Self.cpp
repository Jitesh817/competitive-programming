/*

https://leetcode.com/problems/product-of-array-except-self

*/
#include<vector>

using namespace std;

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        
        vector<int> sol(nums.size());

        int prod = 1;
        
        for(int i = 0; i < nums.size(); i++) {
            sol[i] = i > 0 ? nums[i]*sol[i-1] : nums[i];
        }

        int rightProd = 1;
        for(int i = nums.size()-1; i >= 0; i--) {
            sol[i] = i > 0 ? sol[i-1]*rightProd : rightProd;
            rightProd *= nums[i];
        }

        return sol;
    }
};

int main() {
    return 0;
}