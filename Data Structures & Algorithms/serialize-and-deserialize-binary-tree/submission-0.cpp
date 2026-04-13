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

class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if(!root) return "N,";
        string s=to_string(root->val) + ",";
        s +=serialize(root->left);
        s +=serialize(root->right);
        return s;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        stringstream ss(data);
        return decode(ss);

    }
    TreeNode* decode(stringstream& ss){
    string val;
    getline(ss,val,',');
    if(val=="N") return NULL;
    TreeNode* root=new TreeNode(stoi(val));
    root->left=decode(ss);
    root->right=decode(ss);
    return root;
    }
};
