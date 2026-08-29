#include <algorithm>
#include <map>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    struct node{
        int st;
        int ed;
    }a[1005];

    static bool cmp(node a, node b){
        if(a.st != b.st) return a.st < b.st;
        return a.ed < b.ed;
    }

    vector<int> partitionLabels(string s){
        map<int, int> mp;
        vector<int> ans;
        for(int i = 0;i < 1005;i++) a[i].st = 505, a[i].ed = 505;
        for(int i = 0;i < s.size();i++){
            if(mp.find((s[i] - 'a')) != mp.end()){
                mp[s[i] - 'a'] = i;
            }else {
                a[s[i] - 'a'].st = i;
                mp[s[i] - 'a'] = i;
            }
        }

        for (auto &x : mp) {
            a[x.first].ed = x.second;
        }
        sort(a, a + 26, cmp);
        int ed = a[0].ed;
        int st = a[0].st;

        for(int i = 1;i < 26;i++){
            if(a[i].st == 505 && a[i].ed == 505) continue;
            if(a[i].st < ed){
                ed = max(ed, a[i].ed);
            }else{
                ans.push_back(ed - st + 1);
                st = a[i].st;
                ed = a[i].ed;
            }
        }
        ans.push_back(ed-st+1);
        return ans;
    }
};
