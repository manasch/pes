
// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    TreeNode* deleteNode(TreeNode* root, int key) {
        if (root == nullptr) return root;
        
        if (key < root->val) {
            root->left = deleteNode(root->left, key);
            return root;
        }
        else if (key > root->val) {
            root->right = deleteNode(root->right, key);
            return root;
        }
        else { // Case where the root is now the key to be deleted or root->val = val
            
            // if (root->right == nullptr && root->left == nullptr) {
            //     free(root);
            //     return nullptr;
            // }
            // else if (root->right != nullptr || root->left != nullptr) {
            //     TreeNode* temp;
            //     if (root->right) temp = root->right;
            //     else temp = root->left;
            //     free(root);
            //     return temp;
            // }
            
            if (root->left == nullptr) return root->right; // single child, left exists
            if (root->right == nullptr) return root->left; // single child, right exists
            auto minnode = root->right; // both the children exist
            while (minnode->left) minnode = minnode->left;
            root->val = minnode->val;
            root->right = deleteNode(root->right, minnode->val);
            return root;
        }
    }
};