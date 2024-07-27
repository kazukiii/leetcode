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
        return buildTreeHelper(preorder, 0, preorder.size(), inorder, 0,
                               inorder.size());
    }

private:
    TreeNode* buildTreeHelper(const vector<int>& preorder, int preorder_start, int preorder_end,
                              const vector<int>& inorder, int inorder_start, int inorder_end) {
        if (preorder_start == preorder_end && inorder_start == inorder_end) return nullptr;

        int root_value = preorder[preorder_start];
        TreeNode* root = new TreeNode(root_value);

        int inorder_root_index = inorder_start;
        while (inorder[inorder_root_index] != root_value) {
            inorder_root_index++;
        }

        int left_tree_size = inorder_root_index - inorder_start;
        root->left = buildTreeHelper(preorder, preorder_start + 1, preorder_start + left_tree_size + 1,
                                     inorder, inorder_start, inorder_root_index);
        root->right = buildTreeHelper(preorder, preorder_start + left_tree_size + 1, preorder_end,
                                      inorder, inorder_root_index + 1, inorder_end);
        return root;
    }
};
