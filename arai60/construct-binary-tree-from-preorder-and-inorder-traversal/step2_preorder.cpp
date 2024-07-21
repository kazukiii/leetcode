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

        TreeNode* root = new TreeNode(preorder[0]);
        for (int i = 1; i < preorder.size(); i++) {
            TreeNode* node = root;
            int next_node_value = preorder[i];
            while (true) {
                if (inorder_value_to_index[next_node_value] < inorder_value_to_index[node->val]) {
                    if (!node->left) {
                        node->left = new TreeNode(next_node_value);
                        break;
                    }
                    node = node->left;
                } else {
                    if (!node->right) {
                        node->right = new TreeNode(next_node_value);
                        break;
                    }
                    node = node->right;
                }
            }
        }
        return root;
    }
};
