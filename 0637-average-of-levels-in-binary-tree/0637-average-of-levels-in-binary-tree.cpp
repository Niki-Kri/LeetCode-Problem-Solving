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
    vector<double> averageOfLevels(TreeNode* root) {
        vector<double> averages;
        if (root == nullptr) {
            return averages;
        }
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            int level_size = q.size();
            double level_sum = 0; 
            for (int i = 0; i < level_size; ++i) {
                TreeNode* current = q.front();
                q.pop();
                level_sum += current->val;
                if (current->left != nullptr) {
                    q.push(current->left);
                }
                if (current->right != nullptr) {
                    q.push(current->right);
                }
            }
            averages.push_back(level_sum / level_size);
        }
        return averages;
    }
};