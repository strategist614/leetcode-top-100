#include <vector>

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
    vector<TreeNode*> v;

    void dfs(TreeNode* node){
        if(node == nullptr) return;
        v.push_back(node);
        dfs(node->left);
        dfs(node->right);
    }

    void flatten(TreeNode* root) {
        if(root == nullptr) return;
        dfs(root);
        for(int i = 0;i < v.size() - 1;i++)
        {
            v[i]->left = nullptr;
            v[i]->right = v[i + 1];
        }
        v.back()->left = nullptr;
        v.back()->right = nullptr;
    }
};
