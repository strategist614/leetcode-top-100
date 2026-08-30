#include <algorithm>
#include <climits>
#include <vector>

using namespace std;

class Solution {
public:
    int numSquares(int n) {
        vector<int> dp(n + 1, INT_MAX);

        dp[0] = 0;

        for(int i = 1; i * i <= n; i++){
            int x = i * i;

            for(int j = x; j <= n; j++){
                dp[j] = min(dp[j], dp[j - x] + 1);
            }
        }

        return dp[n];
    }
};
