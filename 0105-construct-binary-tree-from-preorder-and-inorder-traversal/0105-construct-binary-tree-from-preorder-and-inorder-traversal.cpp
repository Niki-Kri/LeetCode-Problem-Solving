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
    int idx = 0;
    TreeNode* buildTree(vector<int>& pre, vector<int>& in) {
        return build(pre, in, 0, in.size() - 1);
    }
    TreeNode* build(vector<int>& pre, vector<int>& in, int l, int r) {
        if (l > r) {
            return NULL;
        }
        int val = pre[idx];
        TreeNode* root = new TreeNode(val);
        idx++;
        int pos = 0;
        for (int i = l; i <= r; i++) {
            if (in[i] == val) {
                pos = i;
                break;
            }
        }
        root->left = build(pre, in, l, pos - 1);
        root->right = build(pre, in, pos + 1, r);
        return root;
    }
};