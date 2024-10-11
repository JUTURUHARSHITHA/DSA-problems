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
        vector<vector<int>>ans;
        queue<TreeNode *>q;
        if(root==NULL) return ans;
        q.push(root);
        bool f=false;
        while(!q.empty()){
            vector<int>v;
            int n=q.size();
            
            for(int i=0;i<n;i++){
                TreeNode* temp=q.front();
                v.push_back(temp->val);
                q.pop();
                if(temp->left!=NULL) q.push(temp->left);
                if(temp->right!=NULL) q.push(temp->right);
            }
            if(f){
                reverse(v.begin(),v.end());
                f=false;
            }else{
                f=true; 
            }
            ans.push_back(v);
        }
        return ans;
    }
};