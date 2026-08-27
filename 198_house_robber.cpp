#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
    int rob(vector<int>& nums) {
        int dp[105] = {};
        dp[0] = nums[0];
        int maxn = dp[0];
        if(nums.size() >= 2){
            dp[1] = max(nums[0], nums[1]);
            maxn = max(maxn, dp[1]);
        }
        for(int i = 2;i < nums.size();i++){
            for(int j = 0;j < i - 1;j++){
                dp[i] = max(dp[i], dp[j] + nums[i]);
                maxn = max(maxn, dp[i]);
            }
        }
        return maxn;
    }
};
