/*

https://leetcode.com/problems/double-a-number-represented-as-a-linked-list

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

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
    ListNode* reverseList(ListNode* head) {

        ListNode* prev = NULL;
        while(head) {
            ListNode* next = head->next;
            head->next = prev;
            prev = head;
            head = next;
        } 

        return prev;
    }

public:
    ListNode* doubleIt(ListNode* head) {
        
        head = reverseList(head);

        ListNode* curr = head, *prev = NULL;
        int carry = 0;
        while(curr) {
            curr->val = curr->val*2 + carry;
            carry = curr->val/10;
            curr->val %= 10;

            prev = curr;
            curr = curr->next;
        }

        if(carry) {
            prev->next = new ListNode(carry);
        }

        return reverseList(head);
    }
};

int main() {
    return 0;
}