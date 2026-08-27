#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int slow = 0;
        for(int fast = 0;fast < nums.size(); fast++){
            if(nums[fast] != 0){
                if(slow != fast) swap(nums[fast], nums[slow]);
                slow++;
            }
        }
    }
};
