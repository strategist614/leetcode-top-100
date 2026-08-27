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

## 283. 移动零

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

---

## 11. 盛最多水的容器

- 难度：中等
- 题目链接：[LeetCode - 盛最多水的容器](https://leetcode.cn/problems/container-with-most-water/description/?envType=study-plan-v2&envId=top-100-liked)

### 题目描述

给定一个长度为 `n` 的整数数组 `height`。第 `i` 条垂线的两个端点为 `(i, 0)` 和 `(i, height[i])`。

找出其中两条垂线，使它们与 `x` 轴构成的容器能够容纳最多的水，并返回最大水量。容器不能倾斜。

### 示例

```text
输入：height = [1,8,6,2,5,4,8,3,7]
输出：49
```

```text
输入：height = [1,1]
输出：1
```

### 约束

- `n == height.length`
- `2 <= n <= 10^5`
- `0 <= height[i] <= 10^4`

### 我的代码

```cpp
class Solution {
public:
    int maxArea(vector<int>& height) {
        int left = 0;
        int right = height.size() - 1;
        int ans = 0;
        while(left < right){
            ans = max(ans, min(height[left], height[right]) * (right - left));
            if(height[left] < height[right]) left++;
            else right--;
        }
        return ans;
    }
};
```

### 解法说明

使用左右双指针计算当前容器面积。每次向内移动高度较小的一侧，因为容器的高度由较短的垂线决定，移动较高的一侧无法得到更大的面积。

### 复杂度

- 时间复杂度：`O(n)`
- 空间复杂度：`O(1)`

---

## 15. 三数之和

- 难度：中等
- 题目链接：[LeetCode - 三数之和](https://leetcode.cn/problems/3sum/description/?envType=study-plan-v2&envId=top-100-liked)

### 题目描述

给定一个整数数组 `nums`，找出所有由三个不同下标对应的元素组成、元素之和为 `0` 的三元组。

答案中不能包含重复的三元组，三元组及答案的顺序不限。

### 示例

```text
输入：nums = [-1,0,1,2,-1,-4]
输出：[[-1,-1,2],[-1,0,1]]
```

```text
输入：nums = [0,1,1]
输出：[]
```

```text
输入：nums = [0,0,0]
输出：[[0,0,0]]
```

### 约束

- `3 <= nums.length <= 3000`
- `-10^5 <= nums[i] <= 10^5`

### 我的代码

```cpp
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] > 0)
                break;
            if (i > 0 && nums[i] == nums[i - 1])
                continue;

            int left = i + 1;
            int right = nums.size() - 1;

            while (left < right) {
                int sum = nums[left] + nums[right] + nums[i];
                if (sum < 0)
                    left++;
                else if (sum > 0)
                    right--;
                else {
                    ans.push_back({nums[i], nums[left], nums[right]});
                    while (left < right && nums[left] == nums[left + 1]) {
                        left++;
                    }

                    while (left < right && nums[right] == nums[right - 1]) {
                        right--;
                    }

                    left++;
                    right--;
                }
            }
        }
        return ans;
    }
};
```

### 解法说明

先对数组排序，然后依次固定第一个数，并在它右侧使用双指针寻找另外两个数。根据三数之和与 `0` 的大小移动左右指针，并跳过重复元素，确保结果中没有重复三元组。

### 复杂度

- 时间复杂度：`O(n^2)`
- 空间复杂度：`O(log n)`，取决于排序实现使用的栈空间；不计返回结果
