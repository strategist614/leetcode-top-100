#include <algorithm>
#include <cstring>
#include <vector>

using namespace std;

class Solution {
public:
    int dp[10005];

    int jump(vector<int>& nums) {
        int n = nums.size() - 1;
        memset(dp, 0x3f, sizeof(dp));
        dp[0] = 0;
        for(int i = 0;i < nums.size();i++){
            for(int j = 0;j < i;j++){
                if(j + nums[j] >= i){
                    dp[i] = min(dp[i], dp[j] + 1);
                }
            }
        }

        return dp[n];
    }
};
