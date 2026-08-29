#include <map>

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
    map<int, int> mp;

    int dfs1(TreeNode* node){
        if(node == nullptr) return 0;
        if(node->left == nullptr && node->right == nullptr) {
            mp[node->val] = 1;
            return 1;
        }
        return (mp[node->val] = dfs1(node->left) + dfs1(node->right) + 1);
    }

    int ans = 0;

    void dfs2(TreeNode* node, int k){
        if(node == nullptr) return;
        int l = 0;
        int r = 0;
        if(node->left != nullptr)
            l = mp[node->left->val];
        if(node->right != nullptr)
            r = mp[node->right->val];
        if(k == l + 1) {
            ans = node->val;
            return;
        } else if(k < l + 1){
            dfs2(node->left, k);
        }else if(k > l + 1){
            dfs2(node->right, k - l - 1);
        }
    }

    int kthSmallest(TreeNode* root, int k) {
        dfs1(root);
        dfs2(root, k);
        return ans;
    }
};
