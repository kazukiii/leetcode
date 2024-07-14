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
        vector<TreeNode*> nodes_to_visit;
        nodes_to_visit.push_back(root);
        vector<vector<int>> answer;
        int level = 0;
        while (!nodes_to_visit.empty()) {
            vector<int> values_in_level;
            vector<TreeNode*> nodes_in_next_level;
            for (int i = 0; i < nodes_to_visit.size(); i++) {
                TreeNode* node = nodes_to_visit[i];
                values_in_level.push_back(node->val);
                if (node->left) nodes_in_next_level.push_back(node->left);
                if (node->right) nodes_in_next_level.push_back(node->right);
            }
            if (level % 2 == 1) reverse(values_in_level.begin(), values_in_level.end());
            answer.push_back(move(values_in_level));
            swap(nodes_to_visit, nodes_in_next_level);
            level++;
        }
        return answer;
    }
};
