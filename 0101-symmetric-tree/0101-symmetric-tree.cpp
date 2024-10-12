class Solution {
public:
    bool mir(TreeNode* left, TreeNode* right){
        if(left == NULL && right == NULL) return true;
        if(left == NULL || right == NULL) return false;
        
        return (left->val == right->val) && mir(left->left, right->right) && mir(left->right, right->left);
           }
    bool isSymmetric(TreeNode* root) {
        if (root == NULL) return true;
        return mir(root->left, root->right); 
    }
};