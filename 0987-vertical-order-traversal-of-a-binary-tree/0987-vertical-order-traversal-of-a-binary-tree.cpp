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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        queue<pair<TreeNode*, pair<int, int>>> Q;
        map<int, map<int, multiset<int>>>Mp;

        Q.push({root, {0,0}});

        while(!Q.empty()){
            auto p = Q.front();
            Q.pop();

            TreeNode* ver = p.first;
            int x = p.second.first, y = p.second.second;
            Mp[x][y].insert(ver->val);
            if(ver->left){
                Q.push({ver->left, {x-1, y+1}});
            }
            if(ver->right){
                Q.push({ver->right, {x+1, y+1}});
            }

        }
        vector <vector<int>>ans;
        for(auto p : Mp){
            vector<int>col;
            for(auto q: p.second){
                col.insert(col.end(), q.second.begin(), q.second.end());
            }
            ans.push_back(col);

        }
        return ans;

    }
};