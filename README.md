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

---

## 2. 移动零

- 难度：简单
- 题目链接：[LeetCode - 移动零](https://leetcode.cn/problems/move-zeroes/description/?envType=study-plan-v2&envId=top-100-liked)

### 题目描述

给定一个数组 `nums`，将所有 `0` 移动到数组末尾，同时保持非零元素的相对顺序。

题目要求直接在原数组上进行操作。

### 示例

```text
输入：nums = [0,1,0,3,12]
输出：[1,3,12,0,0]
```

```text
输入：nums = [0]
输出：[0]
```

### 约束

- `1 <= nums.length <= 10^4`
- `-2^31 <= nums[i] <= 2^31 - 1`

### 解法一：辅助数组

```cpp
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        vector<int> ans;
        for(int i = 0;i < nums.size();i++){
            if(nums[i]) ans.push_back(nums[i]);
        }
        for(int i = 0;i < nums.size();i++){
            if(i < ans.size()) nums[i] = ans[i];
            else nums[i] = 0;
        }
    }
};
```

#### 解法说明

先将所有非零元素按原有顺序保存到辅助数组 `ans`，再依次写回 `nums`，剩余位置补 `0`。

#### 复杂度

- 时间复杂度：`O(n)`
- 空间复杂度：`O(n)`

> 该解法能够保持非零元素的相对顺序，但使用了辅助数组，因此不是严格的原地 `O(1)` 空间解法。

### 解法二：双指针（原地）

```cpp
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
```

#### 解法说明

使用 `slow` 指向下一个非零元素应该放置的位置，使用 `fast` 遍历数组。遇到非零元素时，将它与 `slow` 位置的元素交换，然后将 `slow` 向后移动。这样可以原地把所有零移动到数组末尾，并保持非零元素的相对顺序。

#### 复杂度

- 时间复杂度：`O(n)`
- 空间复杂度：`O(1)`
