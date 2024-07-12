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
        queue<TreeNode*> nodes_to_visit;
        nodes_to_visit.push(root);
        while (!nodes_to_visit.empty()) {
            vector<int> current_level_values;
            queue<TreeNode*> next_level_nodes;
            int level_size = nodes_to_visit.size();
            for (int i = 0; i < level_size; i++) {
                TreeNode* node = nodes_to_visit.front();
                nodes_to_visit.pop();
                current_level_values.push_back(node->val);
                if (node->left) next_level_nodes.push(node->left);
                if (node->right) next_level_nodes.push(node->right);
            }
            answer.push_back(move(current_level_values));
            nodes_to_visit = next_level_nodes;
        }
        return answer;
    }
