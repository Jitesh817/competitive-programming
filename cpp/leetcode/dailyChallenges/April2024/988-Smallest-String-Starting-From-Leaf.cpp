/*

https://leetcode.com/problems/smallest-string-starting-from-leaf/

*/

#include<string>
#include<vector>

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
    int asciia = 'a';
public:
    void traverseTree(TreeNode* root, string& prefix, vector<string>& words) {

        if(!root) {
            return;
        }

        prefix.push_back((char)(root->val + asciia));

        if(!root->left && !root->right) {
            string word = prefix;
            reverse(word.begin(), word.end());
            words.push_back(word);
        }

        traverseTree(root->left, prefix, words);
        traverseTree(root->right, prefix, words);

        prefix.pop_back();
    }

    string smallestFromLeaf(TreeNode* root) {
        
        vector<string> words;
        string prefix = "";

        traverseTree(root, prefix, words);

        sort(words.begin(), words.end());
        return words.front();
    }
};

int main() {
    return 0;
}