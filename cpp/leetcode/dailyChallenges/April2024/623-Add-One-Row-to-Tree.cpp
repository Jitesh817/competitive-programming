/*

https://leetcode.com/problems/add-one-row-to-tree/description/

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
    void traverseTree(TreeNode* node, const int& val, const int& depth, int currDepth) {

        if(!node) {
            return;
        }

        if(depth-1 == currDepth) {
            TreeNode* leftNode = new TreeNode(val);
            TreeNode* rightNode = new TreeNode(val);
            
            leftNode->left = node->left;
            node->left = leftNode;

            rightNode->right = node->right;
            node->right = rightNode;
            return;
        }

        traverseTree(node->left, val, depth, currDepth+1);
        traverseTree(node->right, val, depth, currDepth+1);
    }

    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        if(depth == 1) {
            TreeNode* newRoot = new TreeNode(val);
            newRoot->left = root;
            return newRoot;
        }

        traverseTree(root, val, depth, 1);

        return root;
    }
};

int main() {
    return 0;
}