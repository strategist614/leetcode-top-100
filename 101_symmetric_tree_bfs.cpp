#include <queue>
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
    bool isSymmetric(TreeNode* root) {
        if (root == nullptr)
            return true;
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            int size = q.size();
            vector<TreeNode*> level;
            bool hasNode = false;
            for (int i = 0; i < size; i++) {
                TreeNode* node = q.front();
                q.pop();
                level.push_back(node);
                if (node == nullptr) {
                    q.push(nullptr);
                    q.push(nullptr);
                } else {
                    q.push(node->left);
                    q.push(node->right);
                    if (node->left || node->right)
                        hasNode = true;
                }
            }
            // 判断这一层是否镜像
            int l = 0;
            int r = level.size() - 1;
            while (l < r) {
                if (level[l] == nullptr && level[r] == nullptr) {
                    l++;
                    r--;
                    continue;
                }
                if (level[l] == nullptr || level[r] == nullptr)
                    return false;
                if (level[l]->val != level[r]->val)
                    return false;
                l++;
                r--;
            }
            // 下一层已经全是 null，不用继续
            if (!hasNode)
                break;
        }
        return true;
    }
};
