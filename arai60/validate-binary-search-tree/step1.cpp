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
    bool isValidBST(TreeNode* root) {
        return isValidBSTHelper(root, numeric_limits<long long>::min(), numeric_limits<long long>::max());
    }

private:
    bool isValidBSTHelper(TreeNode* root, long long lower, long long upper) {
        if (!root) return true;
        if (!(lower < root->val && root->val < upper)) return false;
        return isValidBSTHelper(root->left, lower, root->val) && isValidBSTHelper(root->right, root->val, upper);
    }
};
