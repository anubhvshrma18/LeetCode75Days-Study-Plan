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
    int maxLevelSum(TreeNode* root) {
        if(!root){
            return 0;
        }
        queue<TreeNode*> q;
        q.push(root);
        int max=root->val,mxl=1;
        int level=1;
        while(!q.empty()){
            int size=q.size();
            int sum=0;
            // level++;
            while(size--){
                TreeNode* node=q.front();
                q.pop();
                sum+=node->val;
                if(node->left){
                    q.push(node->left);
                }   
                if(node->right){
                    q.push(node->right);
                }
            
            }
            if(sum>max){
                max=sum;
                mxl=level;
            }
            level++;
        }
        
        return mxl;
    }
};