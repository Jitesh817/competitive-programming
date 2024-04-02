/*

https://leetcode.com/problems/isomorphic-strings/

*/

#include<string>

using namespace std;

class Solution {
public:
    bool isIsomorphic(string s, string t) {

        if(s.size() != t.size()) {
            return false;
        }

        unordered_map<char, char> isomorphMap;
        unordered_map<char, bool> characterTaken;

        for(int i = 0; i < s.size(); i++) {
            if(isomorphMap.find(s[i]) == isomorphMap.end() && !characterTaken[t[i]]) {
                isomorphMap[s[i]] = t[i];
                characterTaken[t[i]] = true;
            }

            if(isomorphMap[s[i]] != t[i]) {
                return false;
            }
        }

        return true;
    }
};

int main() {
    return 0;
}