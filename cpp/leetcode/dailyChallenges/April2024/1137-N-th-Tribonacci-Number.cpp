/*

https://leetcode.com/problems/n-th-tribonacci-number/description/

*/

class Solution {
public:
    int tribonacci(int n) {

        int trib[3] = {0, 1, 1};

        for(int i = 3; i <= n; i++) {
            trib[i%3] = trib[0] + trib[1] + trib[2];
        }

        return trib[n%3];
    }
};

int main() {
    return 0;
}