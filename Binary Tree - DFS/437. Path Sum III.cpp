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
    
    int calc(TreeNode* root,int sum,int ta){
        if(!root){
            return 0;
        }
        int ans=0;
        if(sum+root->val==ta){
             ans+=1;
        }
        int l=calc(root->left,sum+root->val,ta);
        int r=calc(root->right,sum+root->val,ta);
        return l+r+ans;
    }
    
    int pathSum(TreeNode* root, int targetSum) {
        if(!root){
            return 0;
        }
        int ans=calc(root,0,targetSum);
        int l=pathSum(root->left,targetSum);
        int r=pathSum(root->right,targetSum);
        return ans+l+r;
    }
};