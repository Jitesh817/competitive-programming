/*

https://leetcode.com/problems/sum-root-to-leaf-numbers/

*/

/**
 * Definition for a binary tree node.
*/

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    void traverseTree(TreeNode* node, int& ans, int num) {
        if(!node) {
            return;
        }

        num = num*10 + node->val;
        if(!node->left && !node->right) {
            ans += num;
            return;
        }

        traverseTree(node->left, ans, num);
        traverseTree(node->right, ans, num);
    }

    int sumNumbers(TreeNode* root) {
        int ans = 0;
        traverseTree(root, ans, 0);
        return ans;
    }
};

int main() {
    return 0;
}