/*

https://leetcode.com/problems/boats-to-save-people/description/

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
    int numRescueBoats(vector<int>& people, int limit) {
        int boats = 0;

        sort(people.begin(), people.end());
        int i = 0, j = people.size()-1;

        while(i <= j) {
            if(people[i] + people[j] <= limit) {
                i++;
            }
            j--;
            boats++;
        }

        return boats;
    }
};

int main() {
    return 0;
}