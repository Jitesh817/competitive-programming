/*

https://leetcode.com/problems/min-stack/

*/

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */

#include<stack>
#include<utility>

using namespace std;

class MinStack {

    stack<pair<int, int>>* minStack;

public:
    MinStack() {
        minStack = new stack<pair<int, int>>();
    }
    
    void push(int val) {
        if(minStack->empty()) {
            minStack->push(make_pair(val, val));
            return;
        }

        int currMin = minStack->top().second;
        minStack->push(make_pair(val, min(val, currMin)));
    }
    
    void pop() {
        if(minStack->empty()) {
            return;
        }

        minStack->pop();
    }
    
    int top() {
        return minStack->top().first;
    }
    
    int getMin() {
        return minStack->top().second;
    }
};

int main() {
    return 0;
}