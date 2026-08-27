#include <vector>

using namespace std;

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int sum1[100000 + 5];
        int sum2[100000 + 5];
        sum1[0] = nums[0];
        for(int i = 1;i < nums.size();i++)
        {
            sum1[i] = sum1[i - 1] * nums[i];
        }
        sum2[nums.size() - 1] = nums[nums.size() - 1];
        for(int i = nums.size() - 2;i >= 0;i--)
        {
            sum2[i] = sum2[i + 1] * nums[i];
        }
        vector<int> ans;
        for(int i = 0;i < nums.size();i++){
            if(i == 0) ans.push_back(sum2[i+1]);
            else if(i == nums.size() - 1) ans.push_back(sum1[i - 1]);
            else ans.push_back(sum1[i - 1] * sum2[i + 1]);
        }
        return ans;
    }
};
