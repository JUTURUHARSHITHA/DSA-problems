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

      long long prev=LONG_MIN;
       void inorder(TreeNode* a,bool& Is){
         if(!a)
          return ;
          inorder(a->left,Is);
           if(a->val<=prev)
           Is=0;
            prev=a->val;
             inorder(a->right,Is);
         }
public:
    bool isValidBST(TreeNode* a) {
           bool Is=1;
           inorder(a,Is);
            return Is; 
    }
};