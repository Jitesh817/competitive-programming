#include<vector>
#include<unordered_map>

using namespace std;

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int majorityCount = ((nums.size())>>1) + 1;

        unordered_map<int, int> freqMap;

        for(int& num: nums) {
            freqMap[num]++;
            if(freqMap[num] == majorityCount) {
                return num;
            }
        }

        return -1;
    }
};

int main() {
    return 0;
}