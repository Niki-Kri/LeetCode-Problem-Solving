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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if (root == NULL) {
            return ans;
        }
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            int s = q.size();
            vector<int> lvl;
            for (int i = 0; i < s; i++) {
                TreeNode* n = q.front();
                q.pop();
                lvl.push_back(n->val);
                if (n->left != NULL) {
                    q.push(n->left);
                }
                if (n->right != NULL) {
                    q.push(n->right);
                }
            }
            ans.push_back(lvl);
        }
        return ans;
    }
};