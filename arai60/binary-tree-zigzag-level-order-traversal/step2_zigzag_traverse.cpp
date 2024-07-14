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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if (!root) return {};
        vector<TreeNode*> nodes;
        nodes.push_back(root);
        bool left_to_right = true;
        vector<vector<int>> answer;
        while (!nodes.empty()) {
            auto& values_in_level = answer.emplace_back();
            vector<TreeNode*> nodes_in_next_level;
            for (int i = nodes.size() - 1; i >= 0; i--) {
                TreeNode* node = nodes[i];
                values_in_level.push_back(node->val);
                if (left_to_right) {
                    if (node->left) nodes_in_next_level.push_back(node->left);
                    if (node->right) nodes_in_next_level.push_back(node->right);
                } else {
                    if (node->right) nodes_in_next_level.push_back(node->right);
                    if (node->left) nodes_in_next_level.push_back(node->left);
                }
            }
            swap(nodes, nodes_in_next_level);
            left_to_right = !left_to_right;
        }
        return answer;
    }
};
