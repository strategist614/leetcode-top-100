# LeetCode Top 100

## 1. 两数之和

- 难度：简单
- 题目链接：[LeetCode - 两数之和](https://leetcode.cn/problems/two-sum/description/?envType=study-plan-v2&envId=top-100-liked)

### 题目描述

给定一个整数数组 `nums` 和一个整数目标值 `target`，请在数组中找出和为 `target` 的两个整数，并返回它们的数组下标。

每组输入只存在一个有效答案，同一个元素不能重复使用，答案可以按任意顺序返回。

### 示例

```text
输入：nums = [2,7,11,15], target = 9
输出：[0,1]
解释：nums[0] + nums[1] == 9
```

```text
输入：nums = [3,2,4], target = 6
输出：[1,2]
```

```text
输入：nums = [3,3], target = 6
输出：[0,1]
```

### 约束

- `2 <= nums.length <= 10^4`
- `-10^9 <= nums[i] <= 10^9`
- `-10^9 <= target <= 10^9`
- 只存在一个有效答案

### 我的代码

```cpp
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
```

### 复杂度

- 时间复杂度：`O(n log n)`
- 空间复杂度：`O(n)`
