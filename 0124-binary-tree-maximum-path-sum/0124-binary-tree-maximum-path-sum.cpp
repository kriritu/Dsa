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
    int helper(TreeNode* root, int& maxi){
        if(root == nullptr) return 0;

        int leftS =max(0, helper(root->left , maxi)) ; // to aviod neg roots or its child val
        int rightS = max(0, helper(root->right, maxi)) ;

        maxi = max(maxi,root->val + leftS + rightS ) ;

        return (root->val) + max(leftS , rightS);

    }
    int maxPathSum(TreeNode* root) {
        
        int maxi = INT_MIN; // TO AVOID NEG SINGLE ROOT, CANN'T INITIALISE ZERO
        helper(root, maxi);
        return maxi;
    }
};