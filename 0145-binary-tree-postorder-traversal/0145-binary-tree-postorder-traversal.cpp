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
    vector<int> postorderTraversal(TreeNode* root) {
        if(root == nullptr) return {};

        vector<int> result;
        

        vector<int> leftResult = postorderTraversal(root->left);
        result.insert(result.end(), leftResult.begin(), leftResult.end());

        vector<int> rightResult = postorderTraversal(root->right);
        result.insert(result.end(), rightResult.begin(), rightResult.end());

        result.push_back(root->val);

        return result;
        
    }
};