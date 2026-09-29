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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        map<int,int> hashmap;
        for(int i =0; i<inorder.size(); i++){
            hashmap[inorder[i]] = i;
        }
        TreeNode* root = buildTree(preorder, 0, preorder.size()-1, inorder, 0, inorder.size()-1, hashmap);

        return root;
    }
    TreeNode* buildTree(vector<int>&preorder, int preStart, int preEnd, vector<int>&inorder, int inStart, int inEnd, map<int, int>& hashmap){

        if(preStart > preEnd || inStart > inEnd) return nullptr;
        //create root 
        TreeNode* root = new TreeNode(preorder[preStart]);

        //locate this root in inorder traversal
        int inroot = hashmap[root->val];

        //cal range for leftsubree inorder traversl
        int numsleft = inroot - inStart;

        root->left = buildTree(preorder, preStart+1, preStart + numsleft, inorder, inStart, inroot-1, hashmap);
        
        root->right = buildTree(preorder, preStart + numsleft +1, preEnd, inorder, inroot+1, inEnd, hashmap);

        return root;
    }
};