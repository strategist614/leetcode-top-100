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
    vector<int> ans;

    void bfs(TreeNode* root){
        queue<TreeNode*> q;
        q.push(root);
        while(q.size()){
            int size = q.size();
            for(int i = 0;i < size;i++){
                TreeNode* _ = q.front();
                q.pop();
                if(_ != nullptr){
                    if(i == size - 1) ans.push_back(_->val);
                    if(_->left != nullptr)
                        q.push(_->left);
                    if(_->right != nullptr)
                        q.push(_->right);
                }
            }
        }
    }

    vector<int> rightSideView(TreeNode* root) {
        bfs(root);
        return ans;
    }
};
