#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
    struct node {
        int st;
        int ed;
    } a[10005];

    static bool cmp(node a, node b) {
        if (a.st != b.st)
            return a.st < b.st;
        return a.ed < b.ed;
    }

    bool canJump(vector<int>& nums) {
        for(int i = 0;i < nums.size();i++){
            a[i].st = i;
            a[i].ed = i + nums[i];
        }
        int n = nums.size();
        sort(a, a + n, cmp);
        int st = a[0].st;
        int ed = a[0].ed;
        for(int i = 1;i < n - 1;i++){
            if(a[i].st <= ed){
                ed = max(ed, a[i].ed);
                // cout << i << ' ' << ed << endl;
            }else {
                return false;
            }
        }
        // cout << a[0].ed << endl;
        // cout << ed << endl;
        if(ed < n - 1) return false;
        return true;
    }
};
