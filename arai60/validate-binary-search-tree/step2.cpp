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
    bool isValidBST(TreeNode* root) {
        stack<NodeWithRange> nodes_to_visit;
        nodes_to_visit.emplace(root, numeric_limits<long long>::min(), numeric_limits<long long>::max());
        while (!nodes_to_visit.empty()) {
            auto node_with_range = nodes_to_visit.top();
            nodes_to_visit.pop();
            auto node = node_with_range.node;
            if (!node) continue;
            auto lower = node_with_range.lower;
            auto upper = node_with_range.upper;
            if (!(lower < node->val && node->val < upper)) return false;
            nodes_to_visit.emplace(node->left, lower, node->val);
            nodes_to_visit.emplace(node->right, node->val, upper);
        }
        return true;
    }

private:
    struct NodeWithRange {
        TreeNode* node;
        long long lower;
        long long upper;
    };
};
