#include <algorithm>

using namespace std;

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
    int maxn = 0;

    int dfs(TreeNode* node){
        if(node == nullptr) return 0;
        if(node->left == nullptr && node->right == nullptr) return 1;
        int l = dfs(node->left);
        int r = dfs(node->right);
        maxn = max(maxn, l + r);
        return max(l, r) + 1;
    }

    int diameterOfBinaryTree(TreeNode* root) {
        dfs(root);
        return maxn;
    }
};
