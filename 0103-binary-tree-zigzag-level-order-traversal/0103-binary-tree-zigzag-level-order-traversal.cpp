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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> result;
        if(root == nullptr) return result;

        queue<TreeNode*>Q;
        Q.push(root);
        int flag = 1;

        while(!Q.empty()){
            int n = Q.size();
            vector<int>row(n);

            for(int i = 0; i< n; i++){
                TreeNode* node = Q.front();
                Q.pop();

                int index = (flag) ? i: (n-1-i);
                row[index]= node->val;
                if(node->left) Q.push(node->left);
                if(node->right) Q.push(node->right);
          
            }
            flag = !flag;
            result.push_back(row);
        }
        return result;

    }
};