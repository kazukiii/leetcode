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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if (preorder.empty() && inorder.empty()) return nullptr;
        int root_value = preorder[0];
        TreeNode* root = new TreeNode(root_value);

        auto it = find(inorder.begin(), inorder.end(), root_value);
        vector<int> left_tree_inorder(inorder.begin(), it);
        vector<int> right_tree_inorder(it + 1, inorder.end());

        int left_tree_size = left_tree_inorder.size();
        vector<int> left_tree_preorder(preorder.begin() + 1,
                                       preorder.begin() + left_tree_size + 1);
        vector<int> right_tree_preorder(preorder.begin() + left_tree_size + 1,
                                        preorder.end());

        root->left = buildTree(left_tree_preorder, left_tree_inorder);
        root->right = buildTree(right_tree_preorder, right_tree_inorder);
        return root;
    }
};
