#include <map>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int> ans;
        map<int, int> mp;
        map<int, vector<int> > mp1;
        for (int i = 0; i < nums.size(); i++)
            mp[nums[i]]++;
        for (auto &x:mp){
            mp1[x.second].push_back(x.first);
        }
        for(int i = 100000;i>=1;i--){
            if(mp1.find(i) != mp1.end())
            {
                int size = mp1[i].size();
                k -= size;
                for(int j = 0;j < size;j++){
                    ans.push_back(mp1[i][j]);
                }
                // cout << k << endl;
                if(k <= 0) return ans;
            }
        }
        return ans;
    }
};
