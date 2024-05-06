/*

https://leetcode.com/problems/remove-nodes-from-linked-list/description/

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
public:
    ListNode* removeNodes(ListNode* head) {
        stack<ListNode*> s;
        while(head) {
            s.push(head);
            head = head->next;
            s.top()->next = NULL;
        }

        int maxFromRight = INT_MIN;
        ListNode* newHead = NULL;

        while(!s.empty()) {
            ListNode* node = s.top();
            s.pop();
            if(node->val >= maxFromRight) {
                node->next = newHead;
                newHead = node;
                maxFromRight = max(maxFromRight, node->val);
            }
        }

        return newHead;
    }
};

class SolutionII {

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
    ListNode* removeNodes(ListNode* head) {
        head = reverseList(head);

        ListNode* curr = head;
        int maxTillNow = curr->val;

        while(curr->next) {
            if(curr->next->val < maxTillNow) {
                curr->next = curr->next->next;
            } else {
                curr = curr->next;
                maxTillNow = max(maxTillNow, curr->val);
            }
        }

        return reverseList(head);
    }
};

int main() {
    return 0;
}