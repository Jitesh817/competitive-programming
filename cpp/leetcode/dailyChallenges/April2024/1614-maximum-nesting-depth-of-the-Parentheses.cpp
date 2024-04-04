/*

https://leetcode.com/problems/maximum-nesting-depth-of-the-parentheses/

*/

#include<string>

using namespace std;

class Solution {
public:
    int maxDepth(string s) {
        int maxmDepth = 0, currDepth = 0;

        for(char& c: s) {
            if(c == '(') {
                currDepth += 1;

                if(currDepth > maxmDepth) {
                    maxmDepth = currDepth;
                }
            } else if(c == ')') {
                currDepth -= 1;
            }
        }

        return maxmDepth;
    }
};

int main() {
    return 0;
}