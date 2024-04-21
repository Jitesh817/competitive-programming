/*

https://leetcode.com/problems/h-index/

*/

#include<vector>

using namespace std;

class Solution {
public:
    int hIndex(vector<int>& citations) {
        
        sort(citations.begin(), citations.end());

        int n = citations.size();
        int hIndex = 0;
        for(int i = 0; i < n; i++) {
            int poss = n-i < citations[i] ? n-i : citations[i];
            hIndex = hIndex > poss ? hIndex : poss;
        }

        return hIndex;
    }
};

int main() {
    return 0;
}