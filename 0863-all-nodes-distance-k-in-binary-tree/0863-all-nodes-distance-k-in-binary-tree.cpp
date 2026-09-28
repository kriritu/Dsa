/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    void mark_parent(TreeNode* root, unordered_map<TreeNode*,TreeNode*>&track_parent, TreeNode* target){
        queue<TreeNode*> Q;
        Q.push(root);
        while(!Q.empty()){
            TreeNode* curr = Q.front();
            Q.pop();
            if(curr->left){
                track_parent[curr->left] = curr;
                Q.push(curr->left);
            }
            if(curr->right){
                track_parent[curr->right] = curr;
                Q.push(curr->right);
            }
        }
    }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {

        unordered_map<TreeNode*, TreeNode*>track_parent;
        mark_parent(root, track_parent, target);
        unordered_map <TreeNode*, bool> visited;

        queue<TreeNode*> Q;
        Q.push(target);

        visited[target] = true;
        int curr_level = 0;

        while(!Q.empty()){
            int size = Q.size();
            if(curr_level++ == k) break;

            for(int i =0 ; i<size; i++){
                TreeNode* current = Q.front();
                Q.pop();

                if(current->left && !visited[current->left]){
                    Q.push(current->left);
                    visited[current->left] = true;
                }
                if(current->right && !visited[current->right]){
                    Q.push(current->right);
                    visited[current->right] = true;
                }
                if(track_parent[current] && !visited[track_parent[current]]){
                    Q.push(track_parent[current]);
                    visited[track_parent[current]] = true;
                }
            }
       
        }
        vector<int>ans;
        while(!Q.empty()){
            TreeNode* curr = Q.front();
            Q.pop();
            ans.push_back(curr->val);
        }
        return ans;
    }
};