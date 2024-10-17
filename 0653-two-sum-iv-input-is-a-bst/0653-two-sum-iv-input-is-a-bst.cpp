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
class BSTIterator {
    stack<TreeNode*> st;
    bool isNextOrBefore;

    void pushAll(TreeNode* root) {
        while (root) {
            st.push(root);
            root = isNextOrBefore ? root->left : root->right;
        }
    }

public:
    BSTIterator(TreeNode* root, bool isNextOrBeforeExternal) {
        isNextOrBefore = isNextOrBeforeExternal;
        pushAll(root);
    }

    bool hasNext() { return !st.empty(); }

    int next() {
        TreeNode* temp = st.top();
        st.pop();
        isNextOrBefore ? pushAll(temp->right) : pushAll(temp->left);
        return temp->val;
    }
};

class Solution {
public:
    bool findTarget(TreeNode* root, int k) {
        BSTIterator bstIteratorL(root, true), bstIteratorR(root, false);
        int left = bstIteratorL.next(), right = bstIteratorR.next();
        while (left < right) {
            if (left + right == k) {
                return true;
            } else if (bstIteratorL.hasNext() && left + right < k) {
                left = bstIteratorL.next();
            } else if (bstIteratorR.hasNext()) {
                right = bstIteratorR.next();
            } else {
                return false;
            }
        }
        return false;
    }
};