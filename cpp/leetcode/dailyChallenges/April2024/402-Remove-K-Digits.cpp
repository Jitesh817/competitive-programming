/*

https://leetcode.com/problems/remove-k-digits/

*/
#include<string>
#include<stack>

class Solution {
public:
    string removeKdigits(string num, int k) {

        if(k == num.size()) {
            return "0";
        }
        
        stack<char> takeDigits;

        for(char& c: num) {
            while(!takeDigits.empty() && k > 0 && takeDigits.top() > c) {
                takeDigits.pop();
                k--;
            }
            takeDigits.push(c);
        }

        while(k-- > 0) {
            takeDigits.pop();
        }

        string lowestInteger = "";
        while(!takeDigits.empty()) {
            lowestInteger += takeDigits.top();
            takeDigits.pop();
        }

        reverse(lowestInteger.begin(), lowestInteger.end());

        int i = 0;
        while(i < lowestInteger.size()-1 && lowestInteger[i] == '0') {
            i++;
        }

        return lowestInteger.substr(i);
    }
};

using namespace std;

int main() {
    return 0;
}