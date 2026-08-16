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
    TreeNode* buildTree(vector<int>& in, vector<int>& post) {
        int pi = post.size() - 1;
        return build(in, post, 0, in.size() - 1, pi);
    }
    TreeNode* build(vector<int>& in, vector<int>& post, int l, int r, int& pi) {
        if (l > r) return nullptr;
        int val = post[pi];
        TreeNode* root = new TreeNode(val);
        pi--;
        int idx = 0;
        for (int i = l; i <= r; i++) {
            if (in[i] == val) {
                idx = i;
                break;
            }
        }
        root->right = build(in, post, idx + 1, r, pi);
        root->left = build(in, post, l, idx - 1, pi);
        return root;
    }
};