/*

https://leetcode.com/problems/make-the-string-great/

*/
#include<string>
#include<stack>

using namespace std;

class Solution {
    
    bool sameCharacterAndDiffCase(char c1, char c2) {
        return c1 != c2 && tolower(c1) == tolower(c2);
    }

public:
    string makeGood(string s) {
        
        stack<char> charStack;

        for(char& c: s) {
            if(!charStack.empty() && sameCharacterAndDiffCase(c, charStack.top())) {
                charStack.pop();
            } else {
                charStack.push(c);
            }
        }

        string goodString = "";
        while(!charStack.empty()) {
            goodString += charStack.top();
            charStack.pop();
        }

        reverse(goodString.begin(), goodString.end());

        return goodString;
    }
};

int main() {
    return 0;
}