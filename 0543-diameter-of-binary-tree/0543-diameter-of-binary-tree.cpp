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
    int diameterOfBinaryTree(TreeNode* root) {
        int sum = 0;
        diameter(root, sum);
        return sum;
    }
private:
    int diameter(TreeNode* root, int& sum) {
        if (!root)
            return 0;
        int left = diameter(root->left, sum);
        int right = diameter(root->right, sum);
        sum = max(sum, left + right);
        return max(left, right) + 1;
    }
};