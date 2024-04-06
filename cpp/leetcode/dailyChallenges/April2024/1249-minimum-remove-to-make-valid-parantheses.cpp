/*

https://leetcode.com/problems/minimum-remove-to-make-valid-parentheses

*/

#include<string>
#include<stack>

using namespace std;

class Solution {
public:
    string minRemoveToMakeValid(string s) {
        
        stack<int> indexStack;

        for(int i = 0; i < s.size(); i++) {
            if(s[i] == '(') {
                indexStack.push(i);
            } else if (s[i] == ')') {
                if(!indexStack.empty() && s[indexStack.top()] == '(') {
                    indexStack.pop();
                } else {
                    indexStack.push(i);
                }
            }
        }

        string goodString = "";

        for(int i = s.size()-1; i >= 0; i--) {
            if(!indexStack.empty() && indexStack.top() == i) {
                indexStack.pop();
            } else {
                goodString += s[i];
            }
        } 

        reverse(goodString.begin(), goodString.end());
        return goodString;
    }
};

int main() {
    return 0;
}