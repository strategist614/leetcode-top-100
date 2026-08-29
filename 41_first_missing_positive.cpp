#include <cstdlib>
#include <vector>

using namespace std;

class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();

        // 1. 无关数字全部改成 n+1
        for (int i = 0; i < n; i++) {
            if (nums[i] <= 0 || nums[i] > n) {
                nums[i] = n + 1;
            }
        }

        // 2. 用正负号标记 1~n 是否出现
        for (int i = 0; i < n; i++) {
            int x = abs(nums[i]);

            if (x >= 1 && x <= n) {
                nums[x - 1] = -abs(nums[x - 1]);
            }
        }

        // 3. 第一个还是正数的位置，就是没出现
        for (int i = 0; i < n; i++) {
            if (nums[i] > 0) {
                return i + 1;
            }
        }

        return n + 1;
    }
};
