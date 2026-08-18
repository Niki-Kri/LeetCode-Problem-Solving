/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int ans = 0; 
    void dfs(TreeNode* n, int num) {
        if (n == nullptr) {
            return;
        }
        num = num * 10;
        num = num + n->val;
        if (n->left == nullptr && n->right == nullptr) {
            ans = ans + num;
            return;
        }
        dfs(n->left, num);
        dfs(n->right, num);
    }
    int sumNumbers(TreeNode* root) {
        ans = 0; 
        dfs(root, 0); 
        return ans;
    }
};