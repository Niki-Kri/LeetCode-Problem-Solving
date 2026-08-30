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
    int maxSum;
    int maxPathDown(TreeNode* node) {
        if (!node) return 0;
        int left = max(0, maxPathDown(node->left));
        int right = max(0, maxPathDown(node->right));
        maxSum = max(maxSum, left + right + node->val);
        return max(left, right) + node->val;
    }
    
public:
    int maxPathSum(TreeNode* root) {
        maxSum = INT_MIN;
        maxPathDown(root);
        return maxSum;
    }
};