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
    vector<vector<int>> ans;

    void bfs(TreeNode* root){
        if(root == nullptr) return;
        queue<TreeNode*> q;
        q.push(root);
        vector<int> v;
        while(q.size()){
            int size = q.size();
            ans.push_back(v);
            v.clear();
            for(int i = 0;i < size;i++){
                TreeNode* node = q.front();
                q.pop();
                if(node != nullptr){
                    v.push_back(node->val);
                    q.push(node->left);
                    q.push(node->right);
                }
            }
        }
        ans.erase(ans.begin());
    }

    vector<vector<int>> levelOrder(TreeNode* root) {
        bfs(root);
        return ans;
    }
};
