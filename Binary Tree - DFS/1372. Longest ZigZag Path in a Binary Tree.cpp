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
class Pair{
    public:
    int lzp;
    int rzp;
    int mzp;
    
    Pair(){
        
    }
    
    Pair(int lzp,int rzp,int mzp){
        this->lzp=lzp;
        this->rzp=rzp;
        this->mzp=mzp;
    }
};
class Solution {
public:
    

    Pair lp(TreeNode* root){
        if(!root){
            return Pair(-1,-1,0);
        }

        Pair lcp = lp(root->left);
        Pair rcp = lp(root->right);

        Pair P;

        P.lzp = lcp.rzp + 1;
        P.rzp = rcp.lzp + 1;
        P.mzp = max(P.lzp,max(P.rzp,max(lcp.mzp,rcp.mzp)));
        return P;
    }


    int longestZigZag(TreeNode *root)

    {
        Pair ans = lp(root);

        return ans.mzp;
    }
};