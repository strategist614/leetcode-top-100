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
    void dfs(TreeNode* node){
        if(node == nullptr) return;
        if(node->left == nullptr && node->right == nullptr) return;
        TreeNode* left = node->left;
        TreeNode* right = node->right;
        dfs(node->left);
        dfs(node->right);
        node->left = right;
        node->right = left;
    }

    TreeNode* invertTree(TreeNode* root) {
        dfs(root);
        return root;
    }
};
