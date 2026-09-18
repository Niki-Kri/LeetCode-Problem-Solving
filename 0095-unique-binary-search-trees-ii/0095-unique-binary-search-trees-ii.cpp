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
    vector<TreeNode*> generateTrees(int n) {
        if (n == 0) {
            return vector<TreeNode*>();
        }
        return buildTrees(1, n);
    }
    
    vector<TreeNode*> buildTrees(int start, int end) {
        vector<TreeNode*> all_trees;
        if (start > end) {
            all_trees.push_back(nullptr);
            return all_trees;
        }
        for (int i = start; i <= end; i++) {
            vector<TreeNode*> left_trees = buildTrees(start, i - 1);
            vector<TreeNode*> right_trees = buildTrees(i + 1, end);
            for (int l = 0; l < left_trees.size(); l++) {
                for (int r = 0; r < right_trees.size(); r++) {
                    TreeNode* root = new TreeNode(i);
                    root->left = left_trees[l];
                    root->right = right_trees[r];
                    all_trees.push_back(root);
                }
            }
        }
        return all_trees;
    }
};