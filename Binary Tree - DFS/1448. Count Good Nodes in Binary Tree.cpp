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
    int cnt=0;
    void check(TreeNode* root,int val){
        if(!root){
            return;
        }
        if(root->val >= val){
            cnt++;
        }
        check(root->left,max(val,root->val));
        check(root->right,max(val,root->val));
    }
    int goodNodes(TreeNode* root) {
        check(root,-10000);
        return cnt;
    }
};