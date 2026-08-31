#include <vector>

using namespace std;

class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        for(auto &x : nums){
            sum += x;
        }

        if(sum % 2 != 0) return false;
        int val = sum / 2;
        vector<bool> dp(val + 1, false);
        dp[0] = true;

        for(int i = 0;i < nums.size();i++){
            for(int j= val;j >= nums[i];j--){
                dp[j] = dp[j] || dp[j - nums[i]];
            }
        }
        return dp[val];
    }
};
