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
 int maxdepth(TreeNode*root,bool & res){
     if(root==nullptr)
      return 0;
       int l=maxdepth(root->left,res);
        int r=maxdepth(root->right,res);
         if(abs(l-r)>1)
          res= false;
           return max(l+1,r+1);
 }
    bool isBalanced(TreeNode* root) {
        bool res=true;
         maxdepth(root,res);
          return res;  
    }
};