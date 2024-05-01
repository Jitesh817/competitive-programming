/*

https://leetcode.com/problems/reverse-prefix-of-word/

*/

#include <algorithm>
#include <bitset>
#include <complex>
#include <deque>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <tuple>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>

using namespace std;

class Solution {
public:
    string reversePrefix(string word, char ch) {
        int start = 0;
        int end = -1;

        for(int i = 0; i < word.length(); i++) {
            if(word[i] == ch) {
                end = i;
                break;
            }
        }

        while(start < end) {
            char temp = word[start];
            word[start] = word[end];
            word[end] = temp;
            start++;
            end--;
        }

        return word;
    }
};

int main() {
    return 0;
}