/*

https://leetcode.com/problems/integer-to-roman/description

*/

#include<string>

using namespace std;

class Solution {
public:
    string intToRoman(int num) {
        
        string roman = "";

        if(num >= 1000) {
            int q = num/1000;
            num %= 1000;

            while(q-- > 0) {
                roman.append("M");
            }
        }

        if(num >= 100) {
            int q = num/100;
            num %= 100;

            if(q == 4) {
                roman.append("CD");
            } else if (q == 9) {
                roman.append("CM");
            } else {
                if(q > 4) {
                    q -= 5;
                    roman.append("D");
                }

                while(q-- > 0) {
                    roman.append("C");
                }
            }
        }

        if(num >= 10) {
            int q = num/10;
            num %= 10;

            if(q == 4) {
                roman.append("XL");
            } else if (q == 9) {
                roman.append("XC");
            } else {
                if(q > 4) {
                    q -= 5;
                    roman.append("L");
                }

                while(q-- > 0) {
                    roman.append("X");
                }
            }
        }

        if(num) {
            int q = num;

            if(q == 4) {
                roman.append("IV");
            } else if (q == 9) {
                roman.append("IX");
            } else {
                if(q > 4) {
                    q -= 5;
                    roman.append("V");
                }

                while(q-- > 0) {
                    roman.append("I");
                }
            }
        }

        return roman;
    }
};

class SolutionConcise {
public:
    string intToRoman(int num) {
        
        string ones[] = {"", "I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX"};
        string tens[] = {"", "X", "XX", "XXX", "XL", "L", "LX", "LXX", "LXXX", "XC"};
        string hundreds[] = {"", "C", "CC", "CCC", "CD", "D", "DC", "DCC", "DCCC", "CM"};
        string thousands[] = {"", "M", "MM", "MMM"};

        return thousands[num/1000] + hundreds[(num%1000)/100] + tens[(num%100)/10] + ones[(num%10)];
    }
};

int main() {

}