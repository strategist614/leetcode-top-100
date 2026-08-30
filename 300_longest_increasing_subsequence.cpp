#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
    int dp[2505];
    int n;
    int a[2505];

    int lengthOfLIS(vector<int>& nums) {
        n = nums.size();
        for(int i =0;i < nums.size();i++) a[i + 1] = nums[i];
        int maxn = 0;
        for(int i = 1;i <= n;i++){
            dp[i] = 1;
            for(int j = 1;j < i;j++){
                if(a[j] < a[i]) dp[i] = max(dp[i], dp[j] + 1);
            }
        }
        for(int i = 1;i <= n;i++) {
            // cout << dp[i] << endl;
            maxn = max(maxn, dp[i]);
        }
        return maxn;
    }
};
