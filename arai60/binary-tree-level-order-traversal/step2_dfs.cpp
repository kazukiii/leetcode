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
        stack<pair<TreeNode*, int>> nodes_to_visit;
        nodes_to_visit.push({root, 0});
        while (!nodes_to_visit.empty()) {
            auto [node, level] = nodes_to_visit.top();
            nodes_to_visit.pop();
            if (answer.size() == level) {
                answer.push_back({node->val});
            } else {
                answer[level].push_back(node->val);;
            }

            if (node->right) nodes_to_visit.push({node->right, level + 1});
            if (node->left) nodes_to_visit.push({node->left, level + 1});
        }
        return answer;
    }
};
