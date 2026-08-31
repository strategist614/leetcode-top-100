#include <algorithm>
#include <cstring>
#include <vector>

using namespace std;

class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int dp[205][205];
        memset(dp, 0x7f, sizeof dp);
        dp[1][1] = grid[0][0];
        int m = grid.size();
        int n = grid[0].size();
        for(int i = 1;i <= grid.size();i++){
            for(int j = 1;j <= grid[i - 1].size();j++){
                dp[i][j] = min(dp[i][j], dp[i - 1][j] + grid[i - 1][j - 1]);
                dp[i][j] = min(dp[i][j], dp[i][j - 1] + grid[i - 1][j - 1]);
            }
        }
        return dp[m][n];
    }
};
