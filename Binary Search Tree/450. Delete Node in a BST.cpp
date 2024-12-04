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
    int maxi(TreeNode* root){
        if(root->right==nullptr){
            return root->val;
        }
        
        return maxi(root->right);
    }
    TreeNode* deleteNode(TreeNode* root, int data) {
        if(!root){
            return nullptr;
        }
        if(data<root->val){
            root->left= deleteNode(root->left,data);

        }
        else if(data>root->val){
            root->right=deleteNode(root->right,data);
        }
        else{
            if(root->left && root->right){
                int lmx=maxi(root->left);
                root->val=lmx;
                root->left=deleteNode(root->left,lmx);
            }
            else if(root->left){
                return root->left;
            } else if(root->right){
                return root->right;
            }
            else{
                return nullptr;
            }
        }

        return root;
    }
};