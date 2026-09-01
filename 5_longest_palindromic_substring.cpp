#include <string>

using namespace std;

class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();

        int start = 0;
        int maxLen = 1;

        for(int i = 0; i < n; i++){
            // 奇数长度回文
            int l = i;
            int r = i;

            while(l >= 0 && r < n && s[l] == s[r]){
                if(r - l + 1 > maxLen){
                    maxLen = r - l + 1;
                    start = l;
                }

                l--;
                r++;
            }

            // 偶数长度回文
            l = i;
            r = i + 1;

            while(l >= 0 && r < n && s[l] == s[r]){
                if(r - l + 1 > maxLen){
                    maxLen = r - l + 1;
                    start = l;
                }

                l--;
                r++;
            }
        }

        return s.substr(start, maxLen);
    }
};
