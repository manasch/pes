
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
    TreeNode* trimBST(TreeNode* root, int low, int high) {
        if (root == nullptr) return root;

        // if (root->val > high || root->val < low) return deleteNode(root, root->val);
        
        if (root->val < low) return trimBST(root->right, low, high);
        if (root->val > high) return trimBST(root->left, low, high);
        root->left = trimBST(root->left, low, high);
        root->right = trimBST(root->right, low, high); 
        return root;
    }

private:
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