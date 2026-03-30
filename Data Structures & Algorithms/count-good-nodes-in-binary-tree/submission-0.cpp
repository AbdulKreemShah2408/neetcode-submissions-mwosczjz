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
     int helper(TreeNode* root,int maxso){
        if(!root) return 0;
        int count=0;
        if(root->val>=maxso){
             count=1;
        }
        maxso=max(maxso,root->val);


        count +=helper(root->left,maxso);
       count += helper(root->right,maxso);
       return count;
        
     }
    int goodNodes(TreeNode* root) {
        return helper(root,root->val);
        
    }
};
