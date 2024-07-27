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
        queue<NodeAndRange> nodes;
        nodes.emplace(root, numeric_limits<int>::min(), numeric_limits<int>::max());
        for (int i = 1; i < preorder.size(); i++) {
            int next_node_value = preorder[i];
            int inorder_next_node_index = inorder_value_to_index.at(next_node_value);
            while (!nodes.empty()) {
                auto [node, lower_index, upper_index] = nodes.front(); nodes.pop();
                int inorder_cuurent_node_index = inorder_value_to_index.at(node->val);
                if (!(lower_index < inorder_next_node_index &&
                      inorder_next_node_index < upper_index)) continue;

                if (inorder_next_node_index < inorder_cuurent_node_index) {
                    if (node->left) {
                        nodes.emplace(node, lower_index, upper_index);
                        continue;
                    }
                    node->left = new TreeNode(next_node_value);
                    nodes.emplace(node->left, lower_index, inorder_cuurent_node_index);
                } else {
                    if (node->right) {
                        nodes.emplace(node, lower_index, upper_index);
                        continue;
                    }
                    node->right = new TreeNode(next_node_value);
                    nodes.emplace(node->right, inorder_cuurent_node_index, upper_index);
                }
                if (!node->left || !node->right) nodes.emplace(node, lower_index, upper_index);
                break;
            }
        }
        return root;
    }

private:
    struct NodeAndRange {
        TreeNode* node;
        int lower_index;
        int upper_index;
    };
};
