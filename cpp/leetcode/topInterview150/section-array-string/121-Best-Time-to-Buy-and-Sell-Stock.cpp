/*

https://leetcode.com/problems/best-time-to-buy-and-sell-stock

*/

#include<vector>

using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        
        int maxProf = 0;
        int minTillNow = INT_MAX;

        for(int& price: prices) {
            minTillNow = min(minTillNow, price);
            maxProf = max(maxProf, price - minTillNow);
        }

        return maxProf;
    }
};

int main() {
    return 0;
}