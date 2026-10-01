/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if(root == nullptr) return "";

        queue<TreeNode*> q;
        q.push(root);
        string s= ""; 

        while(!q.empty()){
            TreeNode* ele = q.front();
            q.pop();

            if(ele == nullptr ) s.append("null,");
            else s.append(to_string(ele->val)+ ',');

            if(ele!= nullptr){
                q.push(ele->left);
                q.push(ele->right);
            }

        }
        return s;    
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if(data.empty() || data == "null") return nullptr;

        stringstream s(data);
        string str;

        if(!getline(s, str, ',')) return nullptr;
        TreeNode *root = new TreeNode(stoi(str));

        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty()){
            TreeNode* curr = q.front();
            q.pop();

            if(getline(s,str, ',')){
                if(str == "null"){
                    curr->left = nullptr;
                }
                else{

                    TreeNode *leftnode = new TreeNode(stoi(str));
                    curr->left = leftnode;
                    q.push(leftnode);
                } 

            }
            

            if(getline(s,str,',')){
                if(str== "null"){

                    curr->right = nullptr;
                }
                else{

                    TreeNode* rightnode = new TreeNode(stoi(str));
                    curr->right = rightnode;
                    q.push(rightnode);
                }

            }
            
        }
        return root;
        
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));