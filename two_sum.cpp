#include <map>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int, int> mp;
        mp.clear();
        for(int i = 0;i < nums.size();i++){
            mp[nums[i]] = i;
        }
        vector<int> ans;
        int _ = 0;
        for(const auto& [key, value] : mp){
            int another = target - key;
            if(mp.find(another) != mp.end()) {

                _ = target - key;
                ans.push_back(value);
                break;
            }
        }

        for(int i = 0;i < nums.size();i++){
            if(_ == nums[i] && i != ans[0]) ans.push_back(i);
        }
        return ans;
    }
};
