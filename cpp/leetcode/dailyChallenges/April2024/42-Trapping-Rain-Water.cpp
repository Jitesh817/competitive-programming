/*

https://leetcode.com/problems/trapping-rain-water/description/

*/

#include<vector>

using namespace std;

class Solution {
public:
    int trap(vector<int>& height) {
        
        int n = height.size();
        vector<int> maxFromRight(n);

        maxFromRight[n-1] = height[n-1];
        for(int i = n-2; i >= 0; i--) {
            maxFromRight[i] = maxFromRight[i+1] > height[i] ? maxFromRight[i+1] : height[i];
        }

        int trapped = 0;
        int maxFromLeft = height[0];
        for(int i = 1; i < n-1; i++) {
            maxFromLeft = maxFromLeft > height[i] ? maxFromLeft : height[i];
            trapped += min(maxFromLeft, maxFromRight[i]) - height[i];
        }

        return trapped;
    }
};

int main() {
    return 0;
}