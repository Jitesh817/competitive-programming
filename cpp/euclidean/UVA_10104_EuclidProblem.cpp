/*

https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=1045

*/

#include<iostream>

using namespace std;

int gcd(int a, int b, int& x, int &y) {

    if(b == 0) {
        x = 1;
        y = 0;
        return a;
    }

    int x1 = 0, y1 = 0;
    int d = gcd(b, a%b, x1, y1);

    x = y1;
    y = x1 - y1*(a/b);

    return d;
}

int main() {

    int a, b;
    while(cin>>a>>b) {

        int x = 0, y = 0;

        if(a < b) {
            swap(a, b);
        }

        int d = gcd(a, b, x, y);

        cout<<x<<" "<<y<<" "<<d<<endl;
    }

    return 0;
}