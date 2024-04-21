/*

https://leetcode.com/problems/gas-station

*/

#include<vector>
#include<numeric>

using namespace std;

class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int totalGas = accumulate(gas.begin(), gas.end(), 0);
        int totalCost = accumulate(cost.begin(), cost.end(), 0);

        if(totalGas < totalCost) {
            return -1;
        }

        int start = 0;
        int diff = 0;
        for(int i = 0; i < gas.size(); i++) {
            diff += gas[i] - cost[i];
            if(diff < 0) {
                diff = 0;
                start = i+1;
            }
        }

        return start;
    }
};

int main() {
    return 0;
}