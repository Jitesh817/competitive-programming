/*

https://leetcode.com/problems/length-of-last-word

*/


#include<vector>
#include<string>

using namespace std;

class Solution {
public:
    string trimTrailingSpaces(string s) {

        int i = s.size()-1;

        while(i >= 0 && s[i] == ' ') {
            i--;
        }

        return s.substr(0,i+1);
    }

    int lengthOfLastWord(string s) {
       
        s = trimTrailingSpaces(s);

        if(s.empty()) {
            return 0;
        }

        int size = 0;
        for(int i = s.size()-1; i >= 0; i--) {
            if(s[i] == ' ') {
                break;
            }
            size++;
        }

        return size;
    }
};

int main() {
    return 0;
}