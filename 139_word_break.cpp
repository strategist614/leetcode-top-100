#include <map>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        int n = s.size();

        bool dp[305] = {};
        dp[0] = true;

        map<string, int> mp;

        for (int i = 0; i < wordDict.size(); i++) {
            mp[wordDict[i]] = 1;
        }

        for (int i = 1; i <= n; i++) {
            for (int j = 0; j < i; j++) {
                string str = s.substr(j, i - j);

                if (mp[str] && dp[j]) {
                    dp[i] = true;
                }

                if (dp[i])
                    break;
            }
        }

        return dp[n];
    }
};
