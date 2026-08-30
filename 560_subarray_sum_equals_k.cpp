#include <unordered_map>
#include <vector>

using namespace std;

namespace prefix_sum_enumeration {

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int sum[200005];
        int n = nums.size();
        int a[200005];
        for(int i = 0;i < nums.size();i++) a[i+1] = nums[i];

        for(int i = 1;i <= n;i++)
        {
            sum[i] = sum[i - 1] + a[i];
        }
        int ans = 0;
        for(int i = 1;i <= n;i++){
            for(int j=i;j <= n;j++){
                if(sum[j] - sum[i - 1] == k) ans++;
            }
        }
        return ans;
    }
};

} // namespace prefix_sum_enumeration

namespace prefix_sum_hash {

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> mp;

        mp[0] = 1;

        int sum = 0;
        int ans = 0;

        for(int i = 0; i < nums.size(); i++){
            sum += nums[i];

            if(mp.find(sum - k) != mp.end()){
                ans += mp[sum - k];
            }

            mp[sum]++;
        }

        return ans;
    }
};

} // namespace prefix_sum_hash
