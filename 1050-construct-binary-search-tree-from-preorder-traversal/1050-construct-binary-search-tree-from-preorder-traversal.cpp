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
    TreeNode* solve(int mini,int maxi,vector<int>&preorder,int &i){
        if(i>=preorder.size()) return NULL;
        if(preorder[i]<mini  ||  preorder[i]>maxi) return NULL;
        TreeNode*temp= new TreeNode(preorder[i++]);
        temp->left=solve(mini,temp->val,preorder,i);
        temp->right=solve(temp->val,maxi,preorder,i);
        return temp;
    }
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int mini=INT_MIN; int maxi=INT_MAX;
        int i=0;
        return solve(mini,maxi,preorder,i);
    }
};