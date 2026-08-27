#include <vector>

using namespace std;

class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int kk = k % (int)nums.size();
        int cnt = (int)nums.size();
        vector<int> v;
        for(int i = 0;i < nums.size();i++) v.push_back(nums[i]);
        for(int i = 0;i < nums.size();i++) v.push_back(nums[i]);

        nums.clear();

        for(int i = cnt - kk;i < v.size();i++){
            if(cnt == 0) break;
            cnt--;
            nums.push_back(v[i]);
        }
    }
};
