#include <algorithm>
#include <cstring>
#include <string>

using namespace std;

class Solution {
public:
    int minDistance(string word1, string word2) {
        int dp[505][505];
        memset(dp, 0x7f, sizeof dp);
        for (int i = 0; i <= word1.size(); i++)
            dp[i][0] = i;

        for (int j = 0; j <= word2.size(); j++)
            dp[0][j] = j;
        for (int i = 1; i <= word1.size(); i++) {
            for (int j = 1; j <= word2.size(); j++) {
                if (word1[i - 1] == word2[j - 1])
                    dp[i][j] = dp[i - 1][j - 1];
                dp[i][j] = min(dp[i][j], dp[i - 1][j] + 1);
                dp[i][j] = min(dp[i][j], dp[i][j - 1] + 1);
                dp[i][j] = min(dp[i][j], dp[i - 1][j - 1] + 1);
            }
        }
        int m = word1.size();
        int n = word2.size();
        return dp[m][n];
    }
};
