/*

https://leetcode.com/problems/compare-version-numbers/description/

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
    void zeroPadding(vector<int>& v, int numZeroes) {
        if(!numZeroes) {
            return;
        }

        vector<int> zeroes(numZeroes);
        v.insert(end(v), begin(zeroes), end(zeroes));
    }

    vector<int> tokenizeVersion(string& s) {
        stringstream ss(s);
        vector<int> v;
        string token;

        while(getline(ss, token, '.')) {
            v.push_back(stoi(token));
        }

        return v;
    }

public:
    int compareVersion(string version1, string version2) {
        
        vector<int> v1 = tokenizeVersion(version1);
        vector<int> v2 = tokenizeVersion(version2);

        int v1Length = v1.size();
        int v2Length = v2.size();

        if(v1Length > v2Length) {
            zeroPadding(v2, v1Length - v2Length);
        } else {
            zeroPadding(v1, v2Length - v1Length);
        }

        for(int i = 0; i < v1.size(); i++) {
            if(v1[i] == v2[i]) {
                continue; 
            }
            return v1[i] > v2[i] ? 1 : -1;
        }

        return 0;
    }
};

int main() {
    return 0;
}