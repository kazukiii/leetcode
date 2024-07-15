/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    bool isValidBST(TreeNode* root) {
        function<bool(TreeNode*, long long, long long)> is_valid = [&](auto node, auto lower, auto upper) {
            if (!node) return true;
            if (!(lower < node->val && node->val < upper)) return false;
            return is_valid(node->left, lower, node->val) && is_valid(node->right, node->val, upper);
        };
        return is_valid(root, numeric_limits<long long>::min(), numeric_limits<long long>::max());
    }
};
