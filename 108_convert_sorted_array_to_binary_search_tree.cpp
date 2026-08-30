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
    TreeNode* ans = new TreeNode();

    TreeNode* dfs(int l, int r, vector<int> &v) {
        if (l > r)
            return nullptr;
        int mid = (l + r) >> 1;
        // cout << mid << endl;
        TreeNode* node = new TreeNode();
        node->val = v[mid];
        node->left = dfs(l, mid - 1, v);
        node->right = dfs(mid + 1, r, v);
        return node;
    }

    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return dfs(0, nums.size() - 1, nums);
    }
};
