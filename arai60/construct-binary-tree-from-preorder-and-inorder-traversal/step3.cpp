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
        unordered_map<int, int> inorder_value_to_index;
        for (int i = 0; i < inorder.size(); i++) {
            inorder_value_to_index[inorder[i]] = i;
        }
        return buildTreeHelper(preorder, inorder, 0, 0, preorder.size(),
                               inorder_value_to_index);
    }

private:
    TreeNode* buildTreeHelper(const vector<int>& preorder, const vector<int>& inorder,
                              int preorder_start, int inorder_start, int subtree_size,
                              unordered_map<int, int>& inorder_value_to_index) {
        if (subtree_size == 0) return nullptr;
        int root_value = preorder[preorder_start];
        int inorder_root_index = inorder_value_to_index[root_value];
        int left_tree_size = inorder_root_index - inorder_start;
        int right_tree_size = inorder_start + subtree_size - inorder_root_index - 1;

        TreeNode* root = new TreeNode(root_value);
        root->left = buildTreeHelper(preorder, inorder, preorder_start + 1, inorder_start,
                                     left_tree_size, inorder_value_to_index);
        root->right = buildTreeHelper(preorder, inorder, preorder_start + left_tree_size + 1,
                                      inorder_root_index + 1, right_tree_size, inorder_value_to_index);
        return root;
    }
};
