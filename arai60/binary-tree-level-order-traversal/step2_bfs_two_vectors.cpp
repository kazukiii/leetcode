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
    vector<vector<int>> levelOrder(TreeNode* root) {
        if (!root) return vector<vector<int>>();
        vector<vector<int>> answer;
        vector<TreeNode*> nodes_to_visit;
        nodes_to_visit.push_back(root);
        while (!nodes_to_visit.empty()) {
            vector<int> current_level_values;
            vector<TreeNode*> next_level_nodes;
            for (TreeNode* node : nodes_to_visit) {
                current_level_values.push_back(node->val);
                if (node->left) next_level_nodes.push_back(node->left);
                if (node->right) next_level_nodes.push_back(node->right);
            }
            answer.push_back(move(current_level_values));
            nodes_to_visit = next_level_nodes;
        }
        return answer;
    }
};
