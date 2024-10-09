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
  vector<vector<int>>ans;
   void DFS(TreeNode*root,int i){
     if(root==nullptr)
      return;
       if(i>=ans.size()) 
       ans.emplace_back();
        ans[i].push_back(root->val);
         DFS(root->left,i+1);
          DFS(root->right,i+1);
   }
    vector<vector<int>> levelOrder(TreeNode* root) {
         DFS(root,0);
          return ans;
    }
};