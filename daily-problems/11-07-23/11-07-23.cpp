  // Problem Number- 863
 
class Solution {
    void parent(TreeNode* root, unordered_map<TreeNode*, TreeNode*> &par){
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            TreeNode *node = q.front();q.pop();
            if(node->left){
                par[node->left] = node;
                q.push(node->left);
            }
            if(node->right){
                par[node->right] = node;
                q.push(node->right);
            }
        }
    }
public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
         unordered_map<TreeNode*, bool> vis;
         unordered_map<TreeNode*, TreeNode*> par;
         parent(root, par);
         queue<pair<TreeNode*,int>> q;
         q.push({target, 0});
         vis[target] = 1;
         vector<int> res;
         while(!q.empty()){
            TreeNode* node  = q.front().first;
            int   dist      = q.front().second;
            q.pop();
            if(dist==k){
                res.push_back(node->val);
            }
            if(dist==k+1)break;

            if(par[node] && !vis[par[node]]){
                q.push({par[node],dist+1});
                vis[par[node]] = 1;

            }
            if(node->left && !vis[node->left]){
                vis[node->left] = 1;
                q.push({node->left, dist+1});

            }
            if(node->right && !vis[node->right]){
                q.push({node->right, dist+1});
                vis[node->right] = 1;
            }

            
         }
         return res;
    }
};