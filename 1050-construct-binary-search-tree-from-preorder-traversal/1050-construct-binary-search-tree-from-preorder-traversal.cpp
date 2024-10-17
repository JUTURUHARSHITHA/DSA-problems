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
    TreeNode* solve(vector<int>& pre, int &i, int min = INT_MIN, int max = INT_MAX) {
        if (i >= pre.size() || pre[i] < min || pre[i] > max) {
            return nullptr;
        }
        TreeNode* root = new TreeNode(pre[i++]);
        root->left = solve(pre, i, min, root->val);
        root->right = solve(pre, i, root->val, max);
        
        return root;
    }
    TreeNode* bstFromPreorder(vector<int>& pre) {
        int i = 0;
        return solve(pre, i);
    }
};
