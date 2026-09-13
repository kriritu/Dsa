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
    int height(TreeNode* root, int & diameter){
        if(root == nullptr) return 0;
   
        int leftH = height(root->left, diameter);
        int rightH = height(root->right, diameter);
        diameter = max(diameter, leftH+rightH); // 0 was overriding everytime so took max(dia, ....)
        return 1+ max(leftH, rightH);
    }
    int diameterOfBinaryTree(TreeNode* root) {
        int diameter = 0;
        height(root, diameter);
        return diameter;
   
    }
};