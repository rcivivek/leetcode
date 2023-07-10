// Problem Number - 111
class Solution {
public:
    int minDepth(TreeNode* root) {
        if(root==NULL)return 0;
        if(root->left==NULL &&root->right==NULL)return 1;
        return 1+min(root->left==NULL?1e6: minDepth(root->left),root->right==NULL?1e6:minDepth(root->right));
    }
};