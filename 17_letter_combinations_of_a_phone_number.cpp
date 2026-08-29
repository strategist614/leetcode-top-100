#include <map>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    map<string, string> mp;
    vector<string> ans;
    int n;
    string d;

    void dfs(int dep, string s){
        if(dep == n){
            ans.push_back(s);
            return;
        }
        string s_d = "";
        s_d += d[dep];
        string _ = mp[s_d];
        for(int i = 0;i < _.size();i++){
            dfs(dep + 1, s + _[i]);
        }
    }

    vector<string> letterCombinations(string digits) {
        n = digits.size();
        d = digits;
        mp["2"] = "abc";
        mp["3"] = "def";
        mp["4"] = "ghi";
        mp["5"] = "jkl";
        mp["6"] = "mno";
        mp["7"] = "pqrs";
        mp["8"] = "tuv";
        mp["9"] = "wxyz";

        dfs(0, "");
        return ans;
    }
};
