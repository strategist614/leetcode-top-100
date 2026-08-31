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

---

## 53. 最大子数组和

- 难度：中等
- 题目链接：[LeetCode - 最大子数组和](https://leetcode.cn/problems/maximum-subarray/description/?envType=study-plan-v2&envId=top-100-liked)

### 题目描述

给定一个整数数组 `nums`，找出一个和最大的连续子数组，并返回该子数组的最大和。子数组至少包含一个元素。

### 示例

```text
输入：nums = [-2,1,-3,4,-1,2,1,-5,4]
输出：6
解释：连续子数组 [4,-1,2,1] 的和最大，为 6。
```

```text
输入：nums = [1]
输出：1
```

```text
输入：nums = [5,4,-1,7,8]
输出：23
```

### 约束

- `1 <= nums.length <= 10^5`
- `-10^4 <= nums[i] <= 10^4`

### 我的代码

```cpp
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int sum = nums[0];
        int ans = nums[0];
        for(int i = 1;i < nums.size();i++){
            if(sum < 0) sum = nums[i];
            else {
                sum += nums[i];
            }
            ans = max(ans, sum);
        }
        return ans;
    }
};
```

### 解法说明

遍历数组时，`sum` 表示以当前元素结尾的最大子数组和。如果此前的 `sum` 小于 `0`，继续累加只会使结果变小，因此从当前元素重新开始；否则将当前元素加入已有子数组。使用 `ans` 记录遍历过程中出现的最大值。

### 复杂度

- 时间复杂度：`O(n)`
- 空间复杂度：`O(1)`

---

## 56. 合并区间

- 难度：中等
- 题目链接：[LeetCode - 合并区间](https://leetcode.cn/problems/merge-intervals/description/?envType=study-plan-v2&envId=top-100-liked)

### 题目描述

给定一个区间数组 `intervals`，其中 `intervals[i] = [start_i, end_i]`。合并所有相互重叠的区间，返回一组互不重叠且恰好覆盖原有区间的结果。

### 示例

```text
输入：intervals = [[1,3],[2,6],[8,10],[15,18]]
输出：[[1,6],[8,10],[15,18]]
```

```text
输入：intervals = [[1,4],[4,5]]
输出：[[1,5]]
```

```text
输入：intervals = [[4,7],[1,4]]
输出：[[1,7]]
```

### 约束

- `1 <= intervals.length <= 10^4`
- `intervals[i].length == 2`
- `0 <= start_i <= end_i <= 10^4`

### 我的代码

```cpp
class Solution {
public:
    struct node {
        int st;
        int ed;
    } a[10005];

    static bool cmp(const node& a, const node& b) {
        if (a.st != b.st) {
            return a.st < b.st;
        }
        return a.ed < b.ed;
    }

    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> ans;
        for(int i = 0;i < intervals.size();i++){
            a[i].st = intervals[i][0];
            a[i].ed = intervals[i][1];
        }
        int n = (int)intervals.size();
        sort(a, a + n, cmp);
        int end = a[0].ed;
        int start = a[0].st;
        a[n].st = 1e5;
        a[n].ed = 1e5;
        for(int i =1;i <= intervals.size();i++){
            if(a[i].st <= end){
                end = max(end, a[i].ed);
            }else{
                ans.push_back({start, end});
                start = a[i].st;
                end = a[i].ed;
            }
        }
        return ans;
    }
};
```

### 解法说明

先将区间按起点升序、终点升序排列，再依次判断当前区间是否与正在合并的区间重叠。若当前起点不大于已有终点，则扩展终点；否则保存已有区间并开始合并新区间。代码末尾加入哨兵区间，确保最后一个合并结果被写入答案。

### 复杂度

- 时间复杂度：`O(n log n)`
- 空间复杂度：`O(n)`，使用了固定大小的区间数组；不计返回结果

---

## 238. 除了自身以外数组的乘积

- 难度：中等
- 题目链接：[LeetCode - 除了自身以外数组的乘积](https://leetcode.cn/problems/product-of-array-except-self/description/?envType=study-plan-v2&envId=top-100-liked)

### 题目描述

给定一个整数数组 `nums`，返回数组 `answer`，其中 `answer[i]` 等于 `nums` 中除 `nums[i]` 之外其余所有元素的乘积。

要求不使用除法，并在 `O(n)` 时间复杂度内完成。题目保证任意前缀、后缀以及结果的乘积都在 32 位整数范围内。

### 示例

```text
输入：nums = [1,2,3,4]
输出：[24,12,8,6]
```

```text
输入：nums = [-1,1,0,-3,3]
输出：[0,0,9,0,0]
```

### 约束

- `2 <= nums.length <= 10^5`
- `-30 <= nums[i] <= 30`
- `answer[i]` 在 32 位整数范围内

### 我的代码

```cpp
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
```

### 解法说明

分别使用 `sum1` 和 `sum2` 保存前缀乘积与后缀乘积。对于位置 `i`，将它左侧所有元素的乘积与右侧所有元素的乘积相乘，即可得到除 `nums[i]` 之外其余元素的乘积；数组两端分别只使用后缀乘积或前缀乘积。

### 复杂度

- 时间复杂度：`O(n)`
- 空间复杂度：`O(n)`，使用了两个前后缀乘积数组；不计返回结果

---

## 189. 轮转数组

- 难度：中等
- 题目链接：[LeetCode - 轮转数组](https://leetcode.cn/problems/rotate-array/description/?envType=study-plan-v2&envId=top-100-liked)

### 题目描述

给定一个整数数组 `nums`，将数组中的元素向右轮转 `k` 个位置，其中 `k` 是非负数。

### 示例

```text
输入：nums = [1,2,3,4,5,6,7], k = 3
输出：[5,6,7,1,2,3,4]
```

```text
输入：nums = [-1,-100,3,99], k = 2
输出：[3,99,-1,-100]
```

### 约束

- `1 <= nums.length <= 10^5`
- `-2^31 <= nums[i] <= 2^31 - 1`
- `0 <= k <= 10^5`

### 我的代码

```cpp
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int kk = k % (int)nums.size();
        int cnt = (int)nums.size();
        vector<int> v;
        for(int i = 0;i < nums.size();i++) v.push_back(nums[i]);
        for(int i = 0;i < nums.size();i++) v.push_back(nums[i]);

        nums.clear();

        for(int i = cnt - kk;i < v.size();i++){
            if(cnt == 0) break;
            cnt--;
            nums.push_back(v[i]);
        }
    }
};
```

### 解法说明

先计算实际轮转次数 `kk = k % nums.size()`，再将原数组复制两次到辅助数组 `v`。从 `cnt - kk` 位置开始连续取出原数组长度个元素，即可得到向右轮转后的结果。

### 复杂度

- 时间复杂度：`O(n)`
- 空间复杂度：`O(n)`

> 该解法使用辅助数组完成轮转，不是进阶要求中的 `O(1)` 额外空间原地解法。

---

## 73. 矩阵置零

- 难度：中等
- 题目链接：[LeetCode - 矩阵置零](https://leetcode.cn/problems/set-matrix-zeroes/description/?envType=study-plan-v2&envId=top-100-liked)

### 题目描述

给定一个 `m x n` 的矩阵，如果某个元素为 `0`，则将该元素所在行和列的所有元素都设为 `0`。

### 示例

```text
输入：matrix = [[1,1,1],[1,0,1],[1,1,1]]
输出：[[1,0,1],[0,0,0],[1,0,1]]
```

```text
输入：matrix = [[0,1,2,0],[3,4,5,2],[1,3,1,5]]
输出：[[0,0,0,0],[0,4,5,0],[0,3,1,0]]
```

### 约束

- `m == matrix.length`
- `n == matrix[0].length`
- `1 <= m, n <= 200`
- `-2^31 <= matrix[i][j] <= 2^31 - 1`

### 我的代码

```cpp
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        map<int, int> mp1;
        map<int, int> mp2;

        for(int i = 0;i < matrix.size();i++){
            for(int j = 0;j < matrix[i].size();j++){
                if(matrix[i][j] == 0) mp1[i] = 1, mp2[j] = 1;
            }
        }

        for(int i = 0;i < matrix.size();i++){
            for(int j = 0;j < matrix[i].size();j++){
                if(mp1[i] || mp2[j]) matrix[i][j] = 0;
            }
        }
    }
};
```

### 解法说明

第一次遍历矩阵，用 `mp1` 记录包含 `0` 的行，用 `mp2` 记录包含 `0` 的列。第二次遍历时，只要当前位置所在的行或列已被标记，就将该元素设为 `0`。

### 复杂度

- 时间复杂度：`O(mn log(m + n))`，`std::map` 的访问和插入为对数复杂度
- 空间复杂度：`O(m + n)`

> 该解法使用额外映射记录行和列，不是进阶要求中的 `O(1)` 额外空间解法。

---

## 20. 有效的括号

- 难度：简单
- 题目链接：[LeetCode - 有效的括号](https://leetcode.cn/problems/valid-parentheses/?envType=study-plan-v2&envId=top-100-liked)

### 题目描述

给定一个只包含 `(`、`)`、`{`、`}`、`[` 和 `]` 的字符串 `s`，判断字符串是否有效。

有效字符串中的左括号必须由相同类型的右括号按正确顺序闭合，并且每个右括号都有对应的左括号。

### 示例

```text
输入：s = "()"
输出：true
```

```text
输入：s = "()[]{}"
输出：true
```

```text
输入：s = "(]"
输出：false
```

```text
输入：s = "([)]"
输出：false
```

### 约束

- `1 <= s.length <= 10^4`
- `s` 仅由括号 `()[]{}` 组成

### 我的代码

```cpp
class Solution {
public:
    bool isValid(string s) {
        stack<char> ss;
        for(int i = 0;i < s.size();i++){
            if(s[i] == '(' || s[i] == '{' || s[i] == '[') ss.push(s[i]);
            if(s[i] == ')') {
                if(ss.size() && ss.top() == '(') ss.pop();
                else return false;
            }
            if(s[i] == '}') {
                if(ss.size() && ss.top() == '{') ss.pop();
                else return false;
            }
            if(s[i] == ']') {
                if(ss.size() && ss.top() == '[') ss.pop();
                else return false;
            }
        }

        if(ss.size()) return false;
        return true;
    }
};
```

### 解法说明

遍历字符串，遇到左括号时将其压入栈中；遇到右括号时，检查栈顶是否为对应类型的左括号。若不匹配或栈为空，则字符串无效。遍历结束后，只有栈为空时所有括号才完整匹配。

### 复杂度

- 时间复杂度：`O(n)`
- 空间复杂度：`O(n)`

---

## 46. 全排列

- 难度：中等
- 题目链接：[LeetCode - 全排列](https://leetcode.cn/problems/permutations/description/?envType=study-plan-v2&envId=top-100-liked)

### 题目描述

给定一个不含重复数字的数组 `nums`，返回其中所有可能的全排列。答案可以按任意顺序返回。

### 示例

```text
输入：nums = [1,2,3]
输出：[[1,2,3],[1,3,2],[2,1,3],[2,3,1],[3,1,2],[3,2,1]]
```

```text
输入：nums = [0,1]
输出：[[0,1],[1,0]]
```

```text
输入：nums = [1]
输出：[[1]]
```

### 约束

- `1 <= nums.length <= 6`
- `-10 <= nums[i] <= 10`
- `nums` 中的所有整数互不相同

### 我的代码

```cpp
class Solution {
public:
    vector<vector<int>> ans;
    vector<int> path;
    vector<bool> used;

    void dfs(vector<int>& nums) {
        if (path.size() == nums.size()) {
            ans.push_back(path);
            return;
        }

        for (int i = 0; i < nums.size(); i++) {
            if (used[i]) continue;

            path.push_back(nums[i]);
            used[i] = true;

            dfs(nums);

            path.pop_back();
            used[i] = false;
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {
        used.resize(nums.size(), false);

        dfs(nums);

        return ans;
    }
};
```

### 解法说明

使用回溯枚举排列。`path` 保存当前排列，`used[i]` 表示 `nums[i]` 是否已经加入当前路径；每次选择一个尚未使用的元素，递归完成后撤销选择。当路径长度等于数组长度时，得到一个完整排列。

### 复杂度

- 时间复杂度：`O(n · n!)`，需要生成并复制全部排列
- 空间复杂度：`O(n)`，用于递归栈、当前路径和访问标记；不计返回结果

---

## 70. 爬楼梯

- 难度：简单
- 题目链接：[LeetCode - 爬楼梯](https://leetcode.cn/problems/climbing-stairs/description/?envType=study-plan-v2&envId=top-100-liked)

### 题目描述

爬到楼顶需要经过 `n` 个台阶，每次可以爬 `1` 或 `2` 个台阶，求到达楼顶共有多少种不同的方法。

### 示例

```text
输入：n = 2
输出：2
解释：可以爬两次 1 阶，或者一次爬 2 阶。
```

```text
输入：n = 3
输出：3
解释：可以按 1+1+1、1+2 或 2+1 的方式到达楼顶。
```

### 约束

- `1 <= n <= 45`

### 我的代码

```cpp
class Solution {
public:
    int climbStairs(int n) {
        int a[100];
        a[1] = 1;
        a[2] = 2;
        for(int i = 3;i <=n ;i++){
            a[i] = a[i - 1] + a[i - 2];
        }
        return a[n];
    }
};
```

### 解法说明

使用动态规划，`a[i]` 表示爬到第 `i` 阶的方法数。到达第 `i` 阶的最后一步只能来自第 `i - 1` 阶或第 `i - 2` 阶，因此状态转移方程为 `a[i] = a[i - 1] + a[i - 2]`。

### 复杂度

- 时间复杂度：`O(n)`
- 空间复杂度：`O(n)`

> 当前代码使用数组保存所有状态，也可以只保留前两个状态，将额外空间优化为 `O(1)`。

---

## 118. 杨辉三角

- 难度：简单
- 题目链接：[LeetCode - 杨辉三角](https://leetcode.cn/problems/pascals-triangle/description/?envType=study-plan-v2&envId=top-100-liked)

### 题目描述

给定一个整数 `numRows`，生成杨辉三角的前 `numRows` 行。在杨辉三角中，每个数等于它左上方和右上方两个数之和。

### 示例

```text
输入：numRows = 5
输出：[[1],[1,1],[1,2,1],[1,3,3,1],[1,4,6,4,1]]
```

```text
输入：numRows = 1
输出：[[1]]
```

### 约束

- `1 <= numRows <= 30`

### 我的代码

```cpp
class Solution {
public:
    vector<vector<int>> generate(int numRows) {

        int a[35][35] = {};
        a[1][1] = 1;
        a[2][1] = 1;
        a[2][2] = 1;
        vector<vector<int>> ans;
        if(numRows >= 1)
        ans.push_back({1});
        if(numRows >= 2)
        ans.push_back({1,1});
        for(int i = 3;i <= numRows;i++){
            vector<int> _;
            for(int j = 1;j <= i;j++){
                a[i][j] = a[i - 1][j] + a[i - 1][j - 1];
                _.push_back(a[i][j]);
            }
            ans.push_back(_);
        }
        return ans;
    }
};
```

### 解法说明

先保存前两行，再从第三行开始递推。`a[i][j]` 等于上一行相邻的两个数 `a[i - 1][j]` 与 `a[i - 1][j - 1]` 之和。二维数组预先零初始化，使每行两侧边界外的值为 `0`。

### 复杂度

- 时间复杂度：`O(numRows^2)`
- 空间复杂度：`O(numRows^2)`，用于保存递推状态和返回结果

> 原代码中的局部数组未初始化，但递推会读取 `a[i - 1][0]` 等边界位置，可能产生未定义行为；这里补充了 `= {}` 进行零初始化，不改变原有解题思路。

---

## 94. 二叉树的中序遍历

- 难度：简单
- 题目链接：[LeetCode - 二叉树的中序遍历](https://leetcode.cn/problems/binary-tree-inorder-traversal/?envType=study-plan-v2&envId=top-100-liked)

### 题目描述

给定一个二叉树的根节点 `root`，返回它的中序遍历结果。

中序遍历的访问顺序为：左子树、根节点、右子树。

### 示例

```text
输入：root = [1,null,2,3]
输出：[1,3,2]
```

```text
输入：root = []
输出：[]
```

```text
输入：root = [1]
输出：[1]
```

### 约束

- 树中节点数在 `[0, 100]` 范围内
- `-100 <= Node.val <= 100`

### 我的代码

```cpp
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<int> ans;
    void dfs(TreeNode* node){
        if(node == nullptr) return;
        dfs(node->left);
        ans.push_back(node->val);
        dfs(node->right);
    }
    vector<int> inorderTraversal(TreeNode* root) {
        dfs(root);
        return ans;
    }
};
```

### 解法说明

使用递归深度优先遍历。先递归访问左子树，再记录当前节点的值，最后递归访问右子树，得到中序遍历序列。

### 复杂度

- 时间复杂度：`O(n)`，每个节点访问一次
- 空间复杂度：`O(h)`，递归栈深度取决于树高；不计返回结果

---

## 198. 打家劫舍

- 难度：中等
- 题目链接：[LeetCode - 打家劫舍](https://leetcode.cn/problems/house-robber/description/?envType=study-plan-v2&envId=top-100-liked)

### 题目描述

给定一个表示每间房屋存放金额的非负整数数组，相邻房屋不能在同一晚被偷窃。求在不触发警报的情况下能够偷窃到的最高金额。

### 示例

```text
输入：nums = [1,2,3,1]
输出：4
解释：偷窃金额为 1 和 3 的两间房屋，最高金额为 4。
```

```text
输入：nums = [2,7,9,3,1]
输出：12
解释：偷窃金额为 2、9 和 1 的三间房屋，最高金额为 12。
```

### 约束

- `1 <= nums.length <= 100`
- `0 <= nums[i] <= 400`

### 我的代码

```cpp
class Solution {
public:
    int rob(vector<int>& nums) {
        int dp[105] = {};
        dp[0] = nums[0];
        int maxn = dp[0];
        if(nums.size() >= 2){
            dp[1] = max(nums[0], nums[1]);
            maxn = max(maxn, dp[1]);
        }
        for(int i = 2;i < nums.size();i++){
            for(int j = 0;j < i - 1;j++){
                dp[i] = max(dp[i], dp[j] + nums[i]);
                maxn = max(maxn, dp[i]);
            }
        }
        return maxn;
    }
};
```

### 解法说明

使用动态规划枚举当前偷窃的房屋 `i`，再遍历所有与它不相邻的前置房屋 `j`，通过 `dp[j] + nums[i]` 更新当前状态。`maxn` 记录所有状态中的最大金额。

### 复杂度

- 时间复杂度：`O(n^2)`
- 空间复杂度：`O(n)`

> 原代码中的 `dp[i]` 在参与 `max` 比较前未初始化，可能产生未定义行为；这里将数组零初始化，不改变原有动态规划思路。该题也可以通过一维线性状态转移优化到 `O(n)` 时间和 `O(1)` 额外空间。

---

## 104. 二叉树的最大深度

- 难度：简单
- 题目链接：[LeetCode - 二叉树的最大深度](https://leetcode.cn/problems/maximum-depth-of-binary-tree/description/?envType=study-plan-v2&envId=top-100-liked)

### 题目描述

给定一个二叉树的根节点 `root`，返回该二叉树的最大深度。最大深度是从根节点到最远叶子节点的最长路径所包含的节点数。

### 示例

```text
输入：root = [3,9,20,null,null,15,7]
输出：3
```

```text
输入：root = [1,null,2]
输出：2
```

### 约束

- 树中节点数在 `[0, 10^4]` 范围内
- `-100 <= Node.val <= 100`

### 我的代码

```cpp
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int maxn = 0;

    void dfs(TreeNode* root, int depth) {
        if (root == nullptr) {
            return;
        }

        if (root->left == nullptr && root->right == nullptr) {
            maxn = max(maxn, depth);
            return;
        }

        dfs(root->left, depth + 1);
        dfs(root->right, depth + 1);
    }

    int maxDepth(TreeNode* root) {
        if (root == nullptr) return 0;

        dfs(root, 1);
        return maxn;
    }
};
```

### 解法说明

使用深度优先搜索遍历二叉树，并通过参数 `depth` 记录当前节点深度。到达叶子节点时，用当前深度更新最大值 `maxn`；空树的最大深度为 `0`。

### 复杂度

- 时间复杂度：`O(n)`，每个节点至多访问一次
- 空间复杂度：`O(h)`，递归栈深度取决于树高

---

## 226. 翻转二叉树

- 难度：简单
- 题目链接：[LeetCode - 翻转二叉树](https://leetcode.cn/problems/invert-binary-tree/description/?envType=study-plan-v2&envId=top-100-liked)

### 题目描述

给定一棵二叉树的根节点 `root`，翻转这棵二叉树，并返回其根节点。

### 示例

```text
输入：root = [4,2,7,1,3,6,9]
输出：[4,7,2,9,6,3,1]
```

```text
输入：root = [2,1,3]
输出：[2,3,1]
```

```text
输入：root = []
输出：[]
```

### 约束

- 树中节点数在 `[0, 100]` 范围内
- `-100 <= Node.val <= 100`

### 我的代码

```cpp
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    void dfs(TreeNode* node){
        if(node == nullptr) return;
        if(node->left == nullptr && node->right == nullptr) return;
        TreeNode* left = node->left;
        TreeNode* right = node->right;
        dfs(node->left);
        dfs(node->right);
        node->left = right;
        node->right = left;
    }

    TreeNode* invertTree(TreeNode* root) {
        dfs(root);
        return root;
    }
};
```

### 解法说明

使用深度优先搜索递归遍历二叉树。先保存当前节点原来的左右子节点并分别递归翻转子树，再交换当前节点的左右指针。空节点和叶子节点无需处理。

### 复杂度

- 时间复杂度：`O(n)`，每个节点至多访问一次
- 空间复杂度：`O(h)`，递归栈深度取决于树高

---

## 101. 对称二叉树

- 难度：简单
- 题目链接：[LeetCode - 对称二叉树](https://leetcode.cn/problems/symmetric-tree/?envType=study-plan-v2&envId=top-100-liked)

### 题目描述

给定一棵二叉树的根节点 `root`，检查这棵二叉树是否关于中心轴对称。

### 示例

```text
输入：root = [1,2,2,3,4,4,3]
输出：true
```

```text
输入：root = [1,2,2,null,3,null,3]
输出：false
```

### 约束

- 树中节点数在 `[1, 1000]` 范围内
- `-100 <= Node.val <= 100`

### 方法一：层序遍历

```cpp
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        if (root == nullptr)
            return true;
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            int size = q.size();
            vector<TreeNode*> level;
            bool hasNode = false;
            for (int i = 0; i < size; i++) {
                TreeNode* node = q.front();
                q.pop();
                level.push_back(node);
                if (node == nullptr) {
                    q.push(nullptr);
                    q.push(nullptr);
                } else {
                    q.push(node->left);
                    q.push(node->right);
                    if (node->left || node->right)
                        hasNode = true;
                }
            }
            // 判断这一层是否镜像
            int l = 0;
            int r = level.size() - 1;
            while (l < r) {
                if (level[l] == nullptr && level[r] == nullptr) {
                    l++;
                    r--;
                    continue;
                }
                if (level[l] == nullptr || level[r] == nullptr)
                    return false;
                if (level[l]->val != level[r]->val)
                    return false;
                l++;
                r--;
            }
            // 下一层已经全是 null，不用继续
            if (!hasNode)
                break;
        }
        return true;
    }
};
```

#### 解法说明

使用队列逐层遍历，将包括空节点在内的当前层保存到 `level`，再从两端向中间比较节点是否镜像。`hasNode` 用于判断下一层是否还包含真实节点，避免无限处理空节点。

#### 复杂度

- 时间复杂度：最坏为 `O(2^h)`
- 空间复杂度：最坏为 `O(2^h)`

> 该实现会为每个空节点继续加入两个空子节点。对于层数较深且稀疏但仍保持对称的树，队列可能包含大量占位空节点。

### 方法二：递归比较

```cpp
class Solution {
public:
    bool check(TreeNode* a, TreeNode* b) {
        if(a == nullptr && b == nullptr)
            return true;

        if(a == nullptr || b == nullptr)
            return false;

        if(a->val != b->val)
            return false;

        return check(a->left, b->right) &&
               check(a->right, b->left);
    }

    bool isSymmetric(TreeNode* root) {
        if(root == nullptr) return true;

        return check(root->left, root->right);
    }
};
```

#### 解法说明

递归比较两个互为镜像位置的节点：它们必须同时为空，或者值相等且 `a` 的左子树与 `b` 的右子树对称、`a` 的右子树与 `b` 的左子树对称。

#### 复杂度

- 时间复杂度：`O(n)`
- 空间复杂度：`O(h)`，递归栈深度取决于树高

---

## 543. 二叉树的直径

- 难度：简单
- 题目链接：[LeetCode - 二叉树的直径](https://leetcode.cn/problems/diameter-of-binary-tree/description/?envType=study-plan-v2&envId=top-100-liked)

### 题目描述

给定一棵二叉树的根节点，返回这棵树的直径。二叉树的直径是任意两个节点之间最长路径的长度，使用路径上的边数表示，并且该路径不一定经过根节点。

### 示例

```text
输入：root = [1,2,3,4,5]
输出：3
解释：最长路径可以是 [4,2,1,3] 或 [5,2,1,3]。
```

```text
输入：root = [1,2]
输出：1
```

### 约束

- 树中节点数在 `[1, 10^4]` 范围内
- `-100 <= Node.val <= 100`

### 我的代码

```cpp
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int maxn = 0;

    int dfs(TreeNode* node){
        if(node == nullptr) return 0;
        if(node->left == nullptr && node->right == nullptr) return 1;
        int l = dfs(node->left);
        int r = dfs(node->right);
        maxn = max(maxn, l + r);
        return max(l, r) + 1;
    }

    int diameterOfBinaryTree(TreeNode* root) {
        dfs(root);
        return maxn;
    }
};
```

### 解法说明

使用后序遍历计算每个节点左右子树的高度。对于当前节点，经过它的最长路径边数为 `l + r`，用该值更新全局最大直径；当前节点向父节点返回的高度为 `max(l, r) + 1`。

### 复杂度

- 时间复杂度：`O(n)`，每个节点访问一次
- 空间复杂度：`O(h)`，递归栈深度取决于树高

---

## 102. 二叉树的层序遍历

- 难度：中等
- 题目链接：[LeetCode - 二叉树的层序遍历](https://leetcode.cn/problems/binary-tree-level-order-traversal/description/?envType=study-plan-v2&envId=top-100-liked)

### 题目描述

给定一棵二叉树的根节点 `root`，返回其节点值的层序遍历结果，即从上到下逐层、每层从左到右访问所有节点。

### 示例

```text
输入：root = [3,9,20,null,null,15,7]
输出：[[3],[9,20],[15,7]]
```

```text
输入：root = [1]
输出：[[1]]
```

```text
输入：root = []
输出：[]
```

### 约束

- 树中节点数在 `[0, 2000]` 范围内
- `-1000 <= Node.val <= 1000`

### 我的代码

```cpp
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> ans;

    void bfs(TreeNode* root){
        if(root == nullptr) return;
        queue<TreeNode*> q;
        q.push(root);
        vector<int> v;
        while(q.size()){
            int size = q.size();
            ans.push_back(v);
            v.clear();
            for(int i = 0;i < size;i++){
                TreeNode* node = q.front();
                q.pop();
                if(node != nullptr){
                    v.push_back(node->val);
                    q.push(node->left);
                    q.push(node->right);
                }
            }
        }
        ans.erase(ans.begin());
    }

    vector<vector<int>> levelOrder(TreeNode* root) {
        bfs(root);
        return ans;
    }
};
```

### 解法说明

使用队列进行广度优先搜索。每轮记录当前队列长度，只处理这一层的节点，并将左右子节点加入队列。代码会在处理下一层之前把上一层结果加入 `ans`，因此最初会产生一个空数组，遍历结束后将其删除。

### 复杂度

- 时间复杂度：`O(n)`，每个节点访问一次
- 空间复杂度：`O(w)`，`w` 为二叉树的最大层宽；不计返回结果

---

## 98. 验证二叉搜索树

- 难度：中等
- 题目链接：[LeetCode - 验证二叉搜索树](https://leetcode.cn/problems/validate-binary-search-tree/description/?envType=study-plan-v2&envId=top-100-liked)

### 题目描述

给定一棵二叉树的根节点 `root`，判断它是否为有效的二叉搜索树。

有效二叉搜索树的左子树只包含严格小于当前节点的值，右子树只包含严格大于当前节点的值，并且所有子树本身也必须满足这些条件。

### 示例

```text
输入：root = [2,1,3]
输出：true
```

```text
输入：root = [5,1,4,null,null,3,6]
输出：false
解释：根节点为 5，但右子节点为 4。
```

### 约束

- 树中节点数在 `[1, 10^4]` 范围内
- `-2^31 <= Node.val <= 2^31 - 1`

### 我的代码

```cpp
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    bool dfs(TreeNode* node, long long low, long long high) {
        if(node == nullptr)
            return true;

        if(node->val <= low || node->val >= high)
            return false;

        return dfs(node->left, low, node->val) &&
               dfs(node->right, node->val, high);
    }

    bool isValidBST(TreeNode* root) {
        return dfs(root, LLONG_MIN, LLONG_MAX);
    }
};
```

### 解法说明

递归检查每个节点允许取值的开区间 `(low, high)`。进入左子树时将上界更新为当前节点值，进入右子树时将下界更新为当前节点值。使用 `long long` 的最小值和最大值作为根节点的初始边界，避免与合法的 32 位整数节点值冲突。

### 复杂度

- 时间复杂度：`O(n)`，每个节点访问一次
- 空间复杂度：`O(h)`，递归栈深度取决于树高

---

## 230. 二叉搜索树中第 K 小的元素

- 难度：中等
- 题目链接：[LeetCode - 二叉搜索树中第 K 小的元素](https://leetcode.cn/problems/kth-smallest-element-in-a-bst/description/?envType=study-plan-v2&envId=top-100-liked)

### 题目描述

给定一棵二叉搜索树的根节点 `root` 和整数 `k`，查找树中第 `k` 小的元素，其中 `k` 从 `1` 开始计数。

### 示例

```text
输入：root = [3,1,4,null,2], k = 1
输出：1
```

```text
输入：root = [5,3,6,2,4,null,null,1], k = 3
输出：3
```

### 约束

- 树中节点数为 `n`
- `1 <= k <= n <= 10^4`
- `0 <= Node.val <= 10^4`

### 我的代码

```cpp
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    map<int, int> mp;

    int dfs1(TreeNode* node){
        if(node == nullptr) return 0;
        if(node->left == nullptr && node->right == nullptr) {
            mp[node->val] = 1;
            return 1;
        }
        return (mp[node->val] = dfs1(node->left) + dfs1(node->right) + 1);
    }

    int ans = 0;

    void dfs2(TreeNode* node, int k){
        if(node == nullptr) return;
        int l = 0;
        int r = 0;
        if(node->left != nullptr)
            l = mp[node->left->val];
        if(node->right != nullptr)
            r = mp[node->right->val];
        if(k == l + 1) {
            ans = node->val;
            return;
        } else if(k < l + 1){
            dfs2(node->left, k);
        }else if(k > l + 1){
            dfs2(node->right, k - l - 1);
        }
    }

    int kthSmallest(TreeNode* root, int k) {
        dfs1(root);
        dfs2(root, k);
        return ans;
    }
};
```

### 解法说明

第一次 DFS 计算每个节点对应子树的节点数，并以节点值为键保存到 `mp`。第二次 DFS 根据左子树大小 `l` 判断当前节点在本子树中的排名：若 `k == l + 1`，当前节点就是答案；否则进入左子树，或将 `k` 减去左子树和当前节点后进入右子树。

### 复杂度

- 时间复杂度：`O(n log n)`，每个节点需要访问 `std::map`
- 空间复杂度：`O(n)`，用于子树大小映射和递归栈

---

## 199. 二叉树的右视图

- 难度：中等
- 题目链接：[LeetCode - 二叉树的右视图](https://leetcode.cn/problems/binary-tree-right-side-view/description/?envType=study-plan-v2&envId=top-100-liked)

### 题目描述

给定一棵二叉树的根节点 `root`，想象站在二叉树右侧，按照从上到下的顺序返回能够看到的节点值。

### 示例

```text
输入：root = [1,2,3,null,5,null,4]
输出：[1,3,4]
```

```text
输入：root = [1,2,3,4,null,null,null,5]
输出：[1,3,4,5]
```

```text
输入：root = []
输出：[]
```

### 约束

- 树中节点数在 `[0, 100]` 范围内
- `-100 <= Node.val <= 100`

### 我的代码

```cpp
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<int> ans;

    void bfs(TreeNode* root){
        queue<TreeNode*> q;
        q.push(root);
        while(q.size()){
            int size = q.size();
            for(int i = 0;i < size;i++){
                TreeNode* _ = q.front();
                q.pop();
                if(_ != nullptr){
                    if(i == size - 1) ans.push_back(_->val);
                    if(_->left != nullptr)
                        q.push(_->left);
                    if(_->right != nullptr)
                        q.push(_->right);
                }
            }
        }
    }

    vector<int> rightSideView(TreeNode* root) {
        bfs(root);
        return ans;
    }
};
```

### 解法说明

使用队列逐层遍历二叉树。由于每层节点按照从左到右的顺序出队，因此当前层最后一个节点就是从右侧能够看到的节点，将它的值加入结果数组即可。

### 复杂度

- 时间复杂度：`O(n)`，每个节点访问一次
- 空间复杂度：`O(w)`，`w` 为二叉树的最大层宽；不计返回结果

---

## 121. 买卖股票的最佳时机

- 难度：简单
- 题目链接：[LeetCode - 买卖股票的最佳时机](https://leetcode.cn/problems/best-time-to-buy-and-sell-stock/description/?envType=study-plan-v2&envId=top-100-liked)

### 题目描述

给定一个数组 `prices`，其中 `prices[i]` 表示某支股票第 `i` 天的价格。选择一天买入，并在之后的某一天卖出，求一笔交易能够获得的最大利润；如果无法获得利润，则返回 `0`。

### 示例

```text
输入：prices = [7,1,5,3,6,4]
输出：5
解释：价格为 1 时买入，价格为 6 时卖出，最大利润为 5。
```

```text
输入：prices = [7,6,4,3,1]
输出：0
解释：价格持续下降，不进行交易。
```

### 约束

- `1 <= prices.length <= 10^5`
- `0 <= prices[i] <= 10^4`

### 我的代码

```cpp
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minn = 10000;
        int maxn = 0;
        for(int i = 0;i< prices.size();i++){
            maxn = max(maxn, prices[i] - minn);
            if(prices[i] < minn){
                minn = prices[i];
            }
        }
        return maxn;
    }
};
```

### 解法说明

从左到右遍历价格，`minn` 记录当前日期之前出现过的最低价格，`maxn` 记录以当前价格卖出时能够得到的最大利润。每次先更新利润，再更新最低买入价格。

### 复杂度

- 时间复杂度：`O(n)`
- 空间复杂度：`O(1)`

---

## 55. 跳跃游戏

- 难度：中等
- 题目链接：[LeetCode - 跳跃游戏](https://leetcode.cn/problems/jump-game/description/?envType=study-plan-v2&envId=top-100-liked)

### 题目描述

给定一个非负整数数组 `nums`，初始位置在下标 `0`。数组中的每个元素表示从当前位置最多可以向前跳跃的步数，判断能否到达数组的最后一个下标。

### 示例

```text
输入：nums = [2,3,1,1,4]
输出：true
解释：可以先跳到下标 1，再从下标 1 跳到最后一个位置。
```

```text
输入：nums = [3,2,1,0,4]
输出：false
解释：无论如何都会到达下标 3，而该位置无法继续向前跳跃。
```

### 约束

- `1 <= nums.length <= 10^4`
- `0 <= nums[i] <= 10^5`

### 我的代码

```cpp
class Solution {
public:
    struct node {
        int st;
        int ed;
    } a[10005];

    static bool cmp(node a, node b) {
        if (a.st != b.st)
            return a.st < b.st;
        return a.ed < b.ed;
    }

    bool canJump(vector<int>& nums) {
        for(int i = 0;i < nums.size();i++){
            a[i].st = i;
            a[i].ed = i + nums[i];
        }
        int n = nums.size();
        sort(a, a + n, cmp);
        int st = a[0].st;
        int ed = a[0].ed;
        for(int i = 1;i < n - 1;i++){
            if(a[i].st <= ed){
                ed = max(ed, a[i].ed);
                // cout << i << ' ' << ed << endl;
            }else {
                return false;
            }
        }
        // cout << a[0].ed << endl;
        // cout << ed << endl;
        if(ed < n - 1) return false;
        return true;
    }
};
```

### 解法说明

将每个下标 `i` 转换为可跳跃区间 `[i, i + nums[i]]`，排序后从左到右合并所有与当前可达范围相连的区间。`ed` 记录当前能够到达的最远位置；如果某个区间的起点大于 `ed`，说明中间出现了无法跨越的位置。遍历结束后，判断 `ed` 是否覆盖最后一个下标。

### 复杂度

- 时间复杂度：`O(n log n)`，主要来自区间排序
- 空间复杂度：`O(n)`，使用数组保存每个位置对应的区间

> 因为 `a[i].st = i`，这些区间本身已经按起点有序，所以可以省略排序，将时间复杂度进一步优化为 `O(n)`。

---

## 45. 跳跃游戏 II

- 难度：中等
- 题目链接：[LeetCode - 跳跃游戏 II](https://leetcode.cn/problems/jump-game-ii/description/?envType=study-plan-v2&envId=top-100-liked)

### 题目描述

给定一个长度为 `n` 的非负整数数组 `nums`，初始位置在下标 `0`。`nums[i]` 表示从下标 `i` 最多可以向前跳跃的步数，求到达最后一个下标所需的最少跳跃次数。题目保证最后一个下标一定可以到达。

### 示例

```text
输入：nums = [2,3,1,1,4]
输出：2
解释：先从下标 0 跳到下标 1，再从下标 1 跳到最后一个位置。
```

```text
输入：nums = [2,3,0,1,4]
输出：2
```

### 约束

- `1 <= nums.length <= 10^4`
- `0 <= nums[i] <= 1000`
- 题目保证可以到达下标 `n - 1`

### 我的代码

```cpp
class Solution {
public:
    int dp[10005];

    int jump(vector<int>& nums) {
        int n = nums.size() - 1;
        memset(dp, 0x3f, sizeof(dp));
        dp[0] = 0;
        for(int i = 0;i < nums.size();i++){
            for(int j = 0;j < i;j++){
                if(j + nums[j] >= i){
                    dp[i] = min(dp[i], dp[j] + 1);
                }
            }
        }

        return dp[n];
    }
};
```

### 解法说明

使用动态规划，`dp[i]` 表示从下标 `0` 到达下标 `i` 所需的最少跳跃次数。先将所有状态初始化为较大的值，并令 `dp[0] = 0`。对于每个位置 `i`，枚举它前面的所有位置 `j`；当 `j + nums[j] >= i` 时，说明可以从 `j` 跳到 `i`，于是使用 `dp[j] + 1` 更新 `dp[i]`。最终返回 `dp[n - 1]`。

### 复杂度

- 时间复杂度：`O(n^2)`，每个位置都枚举其前面的所有位置
- 空间复杂度：`O(n)`，使用 `dp` 数组保存状态

---

## 763. 划分字母区间

- 难度：中等
- 题目链接：[LeetCode - 划分字母区间](https://leetcode.cn/problems/partition-labels/description/?envType=study-plan-v2&envId=top-100-liked)

### 题目描述

给定一个仅由小写英文字母组成的字符串 `s`，将它划分为尽可能多的片段，使同一个字母最多只出现在一个片段中。返回每个片段的长度，所有片段按原顺序连接后仍然是原字符串。

### 示例

```text
输入：s = "ababcbacadefegdehijhklij"
输出：[9,7,8]
解释：字符串可以划分为 "ababcbaca"、"defegde" 和 "hijhklij"。
```

```text
输入：s = "eccbbbbdec"
输出：[10]
```

### 约束

- `1 <= s.length <= 500`
- `s` 仅由小写英文字母组成

### 我的代码

```cpp
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
```

### 解法说明

先记录每个字母第一次和最后一次出现的位置，将每个出现过的字母转换为一个区间 `[st, ed]`。按照区间起点排序后，从左到右合并存在重叠的区间；相互重叠的字母必须属于同一个片段。当下一个区间与当前区间不重叠时，当前区间就形成一个合法片段，将它的长度加入结果。

### 复杂度

- 时间复杂度：`O(n)`，字母表大小固定为 26，区间排序可以视为常数开销
- 空间复杂度：`O(1)`，只保存固定数量的小写字母区间

---

## 41. 缺失的第一个正数

- 难度：困难
- 题目链接：[LeetCode - 缺失的第一个正数](https://leetcode.cn/problems/first-missing-positive/description/?envType=study-plan-v2&envId=top-100-liked)

### 题目描述

给定一个未排序的整数数组 `nums`，找出数组中没有出现的最小正整数。要求算法的时间复杂度为 `O(n)`，并且只使用常数级额外空间。

### 示例

```text
输入：nums = [1,2,0]
输出：3
```

```text
输入：nums = [3,4,-1,1]
输出：2
```

```text
输入：nums = [7,8,9,11,12]
输出：1
```

### 约束

- `1 <= nums.length <= 10^5`
- `-2^31 <= nums[i] <= 2^31 - 1`

### 我的代码

```cpp
class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();

        // 1. 无关数字全部改成 n+1
        for (int i = 0; i < n; i++) {
            if (nums[i] <= 0 || nums[i] > n) {
                nums[i] = n + 1;
            }
        }

        // 2. 用正负号标记 1~n 是否出现
        for (int i = 0; i < n; i++) {
            int x = abs(nums[i]);

            if (x >= 1 && x <= n) {
                nums[x - 1] = -abs(nums[x - 1]);
            }
        }

        // 3. 第一个还是正数的位置，就是没出现
        for (int i = 0; i < n; i++) {
            if (nums[i] > 0) {
                return i + 1;
            }
        }

        return n + 1;
    }
};
```

### 解法说明

对于长度为 `n` 的数组，答案一定处于 `[1, n + 1]`。首先把不在 `[1, n]` 范围内的数字替换为 `n + 1`，避免它们干扰标记。随后把数值 `x` 映射到下标 `x - 1`，通过将该位置的数字改为负数，表示 `x` 已经出现。最后从左到右查找第一个仍为正数的位置，其下标加一就是缺失的最小正整数；如果所有位置都被标记，则答案为 `n + 1`。

### 复杂度

- 时间复杂度：`O(n)`，对数组进行三次线性遍历
- 空间复杂度：`O(1)`，直接使用原数组进行标记

---

## 17. 电话号码的字母组合

- 难度：中等
- 题目链接：[LeetCode - 电话号码的字母组合](https://leetcode.cn/problems/letter-combinations-of-a-phone-number/description/?envType=study-plan-v2&envId=top-100-liked)

### 题目描述

给定一个仅包含数字 `2` 到 `9` 的字符串 `digits`，根据电话按键上数字与字母的对应关系，返回该字符串能够表示的所有字母组合。答案可以按任意顺序返回。

### 示例

```text
输入：digits = "23"
输出：["ad","ae","af","bd","be","bf","cd","ce","cf"]
```

```text
输入：digits = "2"
输出：["a","b","c"]
```

### 约束

- `1 <= digits.length <= 4`
- `digits[i]` 是范围 `['2', '9']` 内的数字

### 我的代码

```cpp
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
```

### 解法说明

先建立数字字符串到候选字母的映射。回溯函数 `dfs(dep, s)` 表示正在为第 `dep` 个数字选择字母，`s` 保存当前已经形成的组合。每一层枚举当前数字对应的所有字母，并递归处理下一个数字；当 `dep == n` 时，一个完整组合生成，将其加入答案数组。

### 复杂度

- 时间复杂度：`O(n * 4^n)`，最多生成 `4^n` 个长度为 `n` 的组合
- 空间复杂度：`O(n)`，不计返回结果时，递归深度和当前字符串长度均为 `n`

> 当前题目约束保证 `digits` 非空。如果将代码用于允许空字符串的接口，需要在调用 `dfs` 前增加 `if (digits.empty()) return {};`，否则会返回一个空字符串组成的数组 `[""]`。

---

## 206. 反转链表

- 难度：简单
- 题目链接：[LeetCode - 反转链表](https://leetcode.cn/problems/reverse-linked-list/description/?envType=study-plan-v2&envId=top-100-liked)

### 题目描述

给定单链表的头节点 `head`，将链表反转，并返回反转后链表的头节点。

### 示例

```text
输入：head = [1,2,3,4,5]
输出：[5,4,3,2,1]
```

```text
输入：head = [1,2]
输出：[2,1]
```

```text
输入：head = []
输出：[]
```

### 约束

- 链表节点数量在 `[0, 5000]` 范围内
- `-5000 <= Node.val <= 5000`

### 我的代码

```cpp
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if(head == nullptr) return nullptr;
        ListNode* curr = head;
        ListNode* nt = curr->next;
        curr->next = nullptr;
        while(nt != nullptr){
            ListNode* ntt = nt->next;
            nt->next = curr;
            curr = nt;
            nt = ntt;
        }
        return curr;
    }
};
```

### 解法说明

使用迭代方式逐个改变链表节点的指向。`curr` 表示已经完成反转部分的头节点，`nt` 表示下一个待处理节点。首先将原头节点的 `next` 置为空，使它成为反转后链表的尾节点。循环中先用 `ntt` 保存后续节点，再让 `nt->next` 指向 `curr`，最后同时向前移动三个指针。循环结束时，`curr` 就是反转后的新头节点。

### 复杂度

- 时间复杂度：`O(n)`，每个链表节点只访问一次
- 空间复杂度：`O(1)`，只使用固定数量的指针变量

---

## 234. 回文链表

- 难度：简单
- 题目链接：[LeetCode - 回文链表](https://leetcode.cn/problems/palindrome-linked-list/description/?envType=study-plan-v2&envId=top-100-liked)

### 题目描述

给定单链表的头节点 `head`，判断该链表是否为回文链表。如果从前向后和从后向前读取的节点值相同，则返回 `true`，否则返回 `false`。

### 示例

```text
输入：head = [1,2,2,1]
输出：true
```

```text
输入：head = [1,2]
输出：false
```

### 约束

- 链表节点数量在 `[1, 10^5]` 范围内
- `0 <= Node.val <= 9`

### 我的代码

```cpp
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    bool isPalindrome(ListNode* head) {
        vector<int> v;
        v.push_back(0);
        while(head != nullptr){
            v.push_back(head->val);
            head = head->next;
        }
        int n = v.size() - 1;
        for(int i = 1;i <= n / 2;i++){
            if(v[i] != v[n - i + 1]) return false;
        }
        return true;
    }
};
```

### 解法说明

先顺序遍历链表，将所有节点值保存到数组中。数组开头额外加入一个占位元素，使有效数据从下标 `1` 开始。随后只遍历数组的前半部分，将第 `i` 个元素与倒数第 `i` 个元素 `v[n - i + 1]` 比较；只要有一组不同，链表就不是回文。所有对应位置都相同则返回 `true`。

### 复杂度

- 时间复杂度：`O(n)`，遍历链表和比较数组各需要线性时间
- 空间复杂度：`O(n)`，使用数组保存全部节点值

> 进阶做法可以使用快慢指针找到链表中点，原地反转后半段并逐个比较，将额外空间复杂度优化为 `O(1)`。

---

## 141. 环形链表

- 难度：简单
- 题目链接：[LeetCode - 环形链表](https://leetcode.cn/problems/linked-list-cycle/description/?envType=study-plan-v2&envId=top-100-liked)

### 题目描述

给定一个链表的头节点 `head`，判断链表中是否存在环。如果沿着某个节点的 `next` 指针能够再次到达已经访问过的节点，则链表有环，返回 `true`；否则返回 `false`。评测系统使用 `pos` 描述链表尾部连接的位置，但它不作为函数参数传入。

### 示例

```text
输入：head = [3,2,0,-4], pos = 1
输出：true
解释：链表尾部连接到下标为 1 的节点。
```

```text
输入：head = [1,2], pos = 0
输出：true
```

```text
输入：head = [1], pos = -1
输出：false
```

### 约束

- 链表节点数量在 `[0, 10^4]` 范围内
- `-10^5 <= Node.val <= 10^5`
- `pos` 为 `-1` 或链表中的有效下标

### 我的代码

```cpp
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
        map<ListNode*, int> mp;
        while(head != nullptr){
            if(mp.find(head) == mp.end()) {
                mp[head] = 1;
                head = head->next;
            }
            else {
                return true;
            }
        }
        return false;
    }
};
```

### 解法说明

使用 `map` 保存已经访问过的节点地址。每次处理当前节点时，先检查它是否已经存在于 `map` 中：如果不存在，就记录该地址并沿 `next` 继续遍历；如果已经存在，说明链表沿指针再次到达了同一个节点，因此存在环。如果最终走到 `nullptr`，则链表没有环。

这里必须记录节点地址而不是节点值，因为不同节点可以拥有相同的 `val`。

### 复杂度

- 时间复杂度：`O(n log n)`，`std::map` 的查询和插入均为 `O(log n)`
- 空间复杂度：`O(n)`，最多保存所有访问过的节点地址

> 使用哈希集合可以将平均时间复杂度优化为 `O(n)`；使用 Floyd 快慢指针可以进一步在 `O(n)` 时间内将额外空间复杂度优化为 `O(1)`。

---

## 21. 合并两个有序链表

- 难度：简单
- 题目链接：[LeetCode - 合并两个有序链表](https://leetcode.cn/problems/merge-two-sorted-lists/description/?envType=study-plan-v2&envId=top-100-liked)

### 题目描述

给定两个按非递减顺序排列的单链表 `list1` 和 `list2`，将它们的所有节点拼接成一个新的非递减链表，并返回合并后链表的头节点。

### 示例

```text
输入：list1 = [1,2,4], list2 = [1,3,4]
输出：[1,1,2,3,4,4]
```

```text
输入：list1 = [], list2 = []
输出：[]
```

```text
输入：list1 = [], list2 = [0]
输出：[0]
```

### 约束

- 两个链表的节点数量均在 `[0, 50]` 范围内
- `-100 <= Node.val <= 100`
- `list1` 和 `list2` 均按非递减顺序排列

### 我的代码

```cpp
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode dummy;
        ListNode* cur = &dummy;
        while(list1 != nullptr && list2 != nullptr){
            if(list1->val <= list2->val){
                cur->next = list1;
                list1 = list1->next;
            }else{
                cur->next = list2;
                list2 = list2->next;
            }
            cur = cur->next;
        }
        cur->next = (list1 != nullptr ? list1 : list2);
        return dummy.next;
    }
};
```

### 解法说明

创建哑节点 `dummy` 作为合并链表的固定起点，使用 `cur` 指向结果链表的尾部。当两个链表都不为空时，比较当前节点值，把较小的节点连接到 `cur->next`，然后移动对应链表指针和 `cur`。循环结束后，最多只有一个链表还有剩余节点，直接将剩余部分整体连接到结果末尾，最后返回 `dummy.next`。

该实现直接复用原链表节点，只改变节点之间的连接关系。

### 复杂度

- 时间复杂度：`O(m + n)`，两个链表中的每个节点最多处理一次
- 空间复杂度：`O(1)`，只使用哑节点和固定数量的指针

---

## 2. 两数相加

- 难度：中等
- 题目链接：[LeetCode - 两数相加](https://leetcode.cn/problems/add-two-numbers/description/?envType=study-plan-v2&envId=top-100-liked)

### 题目描述

给定两个非空链表，它们分别表示两个非负整数。数字按照逆序存储，每个节点只保存一位数字。将两个数相加，并以相同的逆序链表形式返回计算结果。除数字 `0` 外，输入数字没有前导零。

### 示例

```text
输入：l1 = [2,4,3], l2 = [5,6,4]
输出：[7,0,8]
解释：342 + 465 = 807。
```

```text
输入：l1 = [0], l2 = [0]
输出：[0]
```

```text
输入：l1 = [9,9,9,9,9,9,9], l2 = [9,9,9,9]
输出：[8,9,9,9,0,0,0,1]
```

### 约束

- 每个链表的节点数量在 `[1, 100]` 范围内
- `0 <= Node.val <= 9`
- 链表表示的数字不含前导零

### 我的代码

```cpp
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode Dummy;
        ListNode* cur = &Dummy;
        int cnt = 0;
        while(l1 != nullptr && l2 != nullptr){
            ListNode* tmp = new ListNode();
            int _ = cnt + l1->val + l2->val;
            if(_ >= 10){
                tmp->val = _ % 10;
                cnt = _ / 10;
            }else{
                tmp->val = _;
                cnt = 0;
            }
            l1 = l1->next;
            l2 = l2->next;
            cur->next = tmp;
            cur = cur->next;
        }
        while(l1 != nullptr){
            int _ = cnt + l1->val;
            ListNode* tmp = new ListNode();
            tmp->val = _ % 10;
            cnt = _ / 10;
            cur->next = tmp;
            cur = cur->next;
            l1 = l1->next;
        }
        while(l2 != nullptr){
            int _ = cnt + l2->val;
            ListNode* tmp = new ListNode();
            tmp->val = _ % 10;
            cnt = _ / 10;
            cur->next = tmp;
            cur = cur->next;
            l2 = l2->next;
        }
        if(cnt){
            ListNode* tmp = new ListNode();
            tmp->val = cnt;
            cur->next = tmp;
        }
        return Dummy.next;
    }
};
```

### 解法说明

使用 `cnt` 保存上一位产生的进位，并用哑节点 `Dummy` 统一管理结果链表。两个链表都有节点时，将当前两位和进位相加，结果的个位写入新节点，十位继续作为下一轮进位。某个链表遍历结束后，继续处理另一个链表的剩余节点。最后如果 `cnt` 仍不为零，再创建一个节点保存最高位进位。

由于输入链表按照个位到高位的顺序存储，可以从表头开始直接模拟竖式加法，无需反转链表。

### 复杂度

- 时间复杂度：`O(max(m, n))`，遍历两个输入链表的所有节点
- 空间复杂度：`O(max(m, n))`，用于保存返回结果；除结果链表外的额外工作空间为 `O(1)`

---

## 19. 删除链表的倒数第 N 个结点

- 难度：中等
- 题目链接：[LeetCode - 删除链表的倒数第 N 个结点](https://leetcode.cn/problems/remove-nth-node-from-end-of-list/description/?envType=study-plan-v2&envId=top-100-liked)

### 题目描述

给定一个链表的头节点 `head` 和整数 `n`，删除链表的倒数第 `n` 个结点，并返回删除后的链表头节点。

### 示例

```text
输入：head = [1,2,3,4,5], n = 2
输出：[1,2,3,5]
```

```text
输入：head = [1], n = 1
输出：[]
```

```text
输入：head = [1,2], n = 1
输出：[1]
```

### 约束

- 链表节点数量为 `sz`
- `1 <= sz <= 30`
- `0 <= Node.val <= 100`
- `1 <= n <= sz`

### 我的代码

```cpp
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* Dummy = new ListNode();
        Dummy->next = head;
        int size = 0;
        while(head != nullptr){
            size ++;
            head = head->next;
        }
        int cnt = size - n + 1;
        ListNode* cur = Dummy;
        int pos = 0;
        while(cur != nullptr){
            if(pos + 1 == cnt){
                cur->next = cur->next->next;
                break;
            }
            pos++;
            cur = cur->next;
        }
        return Dummy->next;
    }
};
```

### 解法说明

先使用第一次遍历统计链表长度 `size`。倒数第 `n` 个结点对应从前向后的第 `size - n + 1` 个结点，将这个位置记为 `cnt`。随后从哑节点 `Dummy` 开始第二次遍历，找到目标结点的前驱节点，并令前驱的 `next` 跳过目标结点。哑节点能够统一处理删除原头节点的情况。

### 复杂度

- 时间复杂度：`O(L)`，虽然遍历两次，但总访问次数仍与链表长度 `L` 成正比
- 空间复杂度：`O(1)`，只使用固定数量的指针和整数变量

> 进阶做法可以使用间隔为 `n` 的快慢指针，在一次遍历中找到待删除结点的前驱。当前代码使用 `new` 创建哑节点；如果在需要自行管理内存的环境中使用，应在保存返回头指针后释放哑节点，并根据链表所有权规则处理被移除节点。

---

## 24. 两两交换链表中的节点

- 难度：中等
- 题目链接：[LeetCode - 两两交换链表中的节点](https://leetcode.cn/problems/swap-nodes-in-pairs/description/?envType=study-plan-v2&envId=top-100-liked)

### 题目描述

给定一个链表，两两交换其中相邻的节点，并返回交换后的链表头节点。不能修改节点内部保存的值，只能通过改变节点之间的连接关系完成交换。

### 示例

```text
输入：head = [1,2,3,4]
输出：[2,1,4,3]
```

```text
输入：head = []
输出：[]
```

```text
输入：head = [1]
输出：[1]
```

### 约束

- 链表节点数量在 `[0, 100]` 范围内
- `0 <= Node.val <= 100`

### 我的代码

```cpp
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        ListNode* Dummy = new ListNode();
        Dummy->next = head;
        ListNode* cur = new ListNode();
        ListNode* pre = new ListNode();
        cur = head;
        pre = Dummy;
        while(cur != nullptr && cur->next != nullptr){
            ListNode* _ = cur->next->next;
            ListNode* __ = cur->next;
            pre->next = __;
            __->next = cur;
            cur->next = _;
            pre = cur;
            cur = _;
        }
        return Dummy->next;
    }
};
```

### 解法说明

使用哑节点 `Dummy` 处理第一对节点交换后头节点发生变化的情况。`pre` 指向当前待交换节点对的前驱，`cur` 指向这一对中的第一个节点。每轮先保存下一组的起点和当前第二个节点，然后依次修改三条连接：前驱指向第二个节点、第二个节点指向第一个节点、第一个节点指向下一组。完成后移动 `pre` 和 `cur`，继续交换下一对。若最后只剩一个节点，它会保持原位置。

### 复杂度

- 时间复杂度：`O(n)`，每个节点最多处理一次
- 空间复杂度：`O(1)`，只使用固定数量的指针

> `cur` 和 `pre` 创建后立即被其他地址覆盖，这两次 `new` 是多余的并会造成内存泄漏，可以直接写成 `ListNode* cur = head;` 和 `ListNode* pre = Dummy;`。此外，双下划线标识符由 C++ 实现保留，实际工程中建议将 `_`、`__` 改为 `nextPair`、`second` 等语义化名称。

---

## 138. 随机链表的复制

- 难度：中等
- 题目链接：[LeetCode - 随机链表的复制](https://leetcode.cn/problems/copy-list-with-random-pointer/description/?envType=study-plan-v2&envId=top-100-liked)

### 题目描述

给定一个链表，每个节点除 `next` 指针外还有一个 `random` 指针，它可以指向链表中的任意节点或空节点。构造该链表的深拷贝：复制链表必须由全新的节点组成，且所有 `next` 和 `random` 关系与原链表一致，复制链表中的指针不能指向原链表节点。

输入和输出使用 `[val, random_index]` 表示节点，其中 `random_index` 是随机指针指向节点的下标，空指针表示为 `null`。

### 示例

```text
输入：head = [[7,null],[13,0],[11,4],[10,2],[1,0]]
输出：[[7,null],[13,0],[11,4],[10,2],[1,0]]
```

```text
输入：head = [[1,1],[2,1]]
输出：[[1,1],[2,1]]
```

```text
输入：head = [[3,null],[3,0],[3,null]]
输出：[[3,null],[3,0],[3,null]]
```

### 约束

- `0 <= n <= 1000`
- `-10^4 <= Node.val <= 10^4`
- `Node.random` 为 `null` 或指向链表中的节点

### 我的代码

```cpp
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(head == nullptr) return nullptr;

        int pos = 0;
        vector<Node*> v;
        Node* hhead = head;
        map<Node*, int> mp;
        map<int, Node*> mp1;

        // 原节点 -> 下标
        while(head != nullptr){
            mp[head] = pos;
            head = head->next;
            pos++;
        }

        // 创建所有新节点
        head = hhead;
        while(head != nullptr){
            Node* node = new Node(head->val);
            v.push_back(node);
            head = head->next;
        }

        // 连接新链表 next
        Node* Dummy = new Node(0);
        Dummy->next = v[0];
        for(int i = 0; i < v.size() - 1; i++){
            v[i]->next = v[i + 1];
        }

        // 下标 -> 新节点
        Node* curr = Dummy->next;
        pos = 0;
        while(curr != nullptr){
            mp1[pos] = curr;
            curr = curr->next;
            pos++;
        }

        // 设置 random
        curr = Dummy->next;
        head = hhead;
        while(head != nullptr){
            if(head->random == nullptr){
                curr->random = nullptr;
            }else{
                int p = mp[head->random];
                curr->random = mp1[p];
            }

            curr = curr->next;
            head = head->next;
        }

        return Dummy->next;
    }
};
```

### 解法说明

该实现使用下标作为原链表和复制链表之间的桥梁：

1. 第一次遍历建立“原节点地址 → 节点下标”的映射。
2. 为每个原节点创建一个全新的节点，并将新节点依次连接起来。
3. 建立“节点下标 → 新节点地址”的反向映射。
4. 再次同步遍历原链表和新链表。若原节点的 `random` 非空，先查出它指向的原节点下标，再找到同下标的新节点，赋给复制节点的 `random`。

这样复制链表中的 `next` 和 `random` 都只会指向新创建的节点，满足深拷贝要求。

### 复杂度

- 时间复杂度：`O(n log n)`，使用 `std::map` 建立和查询节点映射
- 空间复杂度：`O(n)`，使用数组和两个映射保存节点关系，不计返回的新链表

> 可以直接使用 `map<Node*, Node*>` 保存“原节点 → 新节点”，省去下标中转；换成哈希表后平均时间复杂度为 `O(n)`。还可以将复制节点插入原节点之后，再拆分链表，在 `O(n)` 时间内把映射所需的额外空间优化为 `O(1)`。当前哑节点由 `new` 创建但未释放，在自行管理内存的环境中应处理这一点。

---

## 142. 环形链表 II

- 难度：中等
- 题目链接：[LeetCode - 环形链表 II](https://leetcode.cn/problems/linked-list-cycle-ii/description/?envType=study-plan-v2&envId=top-100-liked)

### 题目描述

给定链表的头节点 `head`，返回链表开始入环的第一个节点；如果链表没有环，则返回 `nullptr`。不允许修改原链表。评测系统使用 `pos` 表示链表尾部连接的位置，但它不作为函数参数传入。

### 示例

```text
输入：head = [3,2,0,-4], pos = 1
输出：返回下标为 1 的链表节点
```

```text
输入：head = [1,2], pos = 0
输出：返回下标为 0 的链表节点
```

```text
输入：head = [1], pos = -1
输出：返回 nullptr
```

### 约束

- 链表节点数量在 `[0, 10^4]` 范围内
- `-10^5 <= Node.val <= 10^5`
- `pos` 为 `-1` 或链表中的有效下标

### 我的代码

```cpp
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        map<ListNode*, int> mp;
        while(head != nullptr){
            if(mp.find(head) != mp.end()){
                return head;
            }
            mp[head] = 1;
            head = head->next;
        }
        return nullptr;
    }
};
```

### 解法说明

从头节点开始顺序遍历，使用 `map` 保存所有已经访问过的节点地址。处理当前节点时，如果它已经存在于 `map` 中，说明沿着环绕行一周后再次到达了该节点；从链表头开始遍历时，第一个重复出现的节点正是入环节点，直接返回它。如果最终到达 `nullptr`，则链表没有环。

记录节点地址而不是节点值，可以正确处理多个节点值相同的情况，并且整个过程不会修改链表。

### 复杂度

- 时间复杂度：`O(n log n)`，`std::map` 的查询和插入均为 `O(log n)`
- 空间复杂度：`O(n)`，最多保存所有访问过的节点地址

> 使用哈希集合可以获得平均 `O(n)` 时间；Floyd 快慢指针先寻找相遇点，再让一个指针回到链表头并与另一个指针同步前进，两者再次相遇的位置就是环入口，可在 `O(n)` 时间和 `O(1)` 额外空间内完成。

---

## 108. 将有序数组转换为二叉搜索树

- 难度：简单
- 题目链接：[LeetCode - 将有序数组转换为二叉搜索树](https://leetcode.cn/problems/convert-sorted-array-to-binary-search-tree/description/?envType=study-plan-v2&envId=top-100-liked)

### 题目描述

给定一个按严格递增顺序排列的整数数组 `nums`，将它转换为一棵高度平衡的二叉搜索树。高度平衡表示每个节点的左右子树高度差不超过 `1`。

### 示例

```text
输入：nums = [-10,-3,0,5,9]
输出：[0,-3,9,-10,null,5]
解释：答案不唯一，只要生成高度平衡的二叉搜索树即可。
```

```text
输入：nums = [1,3]
输出：[3,1]
解释：[1,null,3] 也是正确答案。
```

### 约束

- `1 <= nums.length <= 10^4`
- `-10^4 <= nums[i] <= 10^4`
- `nums` 按严格递增顺序排列

### 我的代码

```cpp
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 *         right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* ans = new TreeNode();

    TreeNode* dfs(int l, int r, vector<int> &v) {
        if (l > r)
            return nullptr;
        int mid = (l + r) >> 1;
        // cout << mid << endl;
        TreeNode* node = new TreeNode();
        node->val = v[mid];
        node->left = dfs(l, mid - 1, v);
        node->right = dfs(mid + 1, r, v);
        return node;
    }

    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return dfs(0, nums.size() - 1, nums);
    }
};
```

### 解法说明

递归处理数组区间 `[l, r]`。每次选择区间中点 `mid` 作为当前子树的根节点：由于数组严格递增，中点左侧的元素都小于根节点，用于构造左子树；右侧的元素都大于根节点，用于构造右子树，因此满足二叉搜索树性质。持续从每个区间的中间位置划分，也能让左右子树规模尽量接近，从而得到高度平衡的树。

当 `l > r` 时区间为空，返回 `nullptr` 作为递归边界。

### 复杂度

- 时间复杂度：`O(n)`，每个数组元素都创建为一个树节点
- 空间复杂度：`O(log n)`，不计返回的树节点时，平衡递归的调用栈深度为 `O(log n)`

> 成员 `ans` 没有参与建树，初始化时创建的节点也不会被释放，可以直接删除这一成员。题目约束保证数组非空；如果复用到允许空数组的接口，建议显式处理空输入，避免 `nums.size() - 1` 的无符号下溢。

---

## 114. 二叉树展开为链表

- 难度：中等
- 题目链接：[LeetCode - 二叉树展开为链表](https://leetcode.cn/problems/flatten-binary-tree-to-linked-list/description/?envType=study-plan-v2&envId=top-100-liked)

### 题目描述

给定二叉树的根节点 `root`，将它原地展开为一个由相同 `TreeNode` 节点组成的单链表。展开后每个节点的 `left` 都必须为 `nullptr`，`right` 指向链表中的下一个节点，并且节点顺序与原二叉树的前序遍历顺序相同。

### 示例

```text
输入：root = [1,2,5,3,4,null,6]
输出：[1,null,2,null,3,null,4,null,5,null,6]
```

```text
输入：root = []
输出：[]
```

```text
输入：root = [0]
输出：[0]
```

### 约束

- 树中节点数量在 `[0, 2000]` 范围内
- `-100 <= Node.val <= 100`

### 我的代码

```cpp
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right)
 *         : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<TreeNode*> v;

    void dfs(TreeNode* node){
        if(node == nullptr) return;
        v.push_back(node);
        dfs(node->left);
        dfs(node->right);
    }

    void flatten(TreeNode* root) {
        if(root == nullptr) return;
        dfs(root);
        for(int i = 0;i < v.size() - 1;i++)
        {
            v[i]->left = nullptr;
            v[i]->right = v[i + 1];
        }
        v.back()->left = nullptr;
        v.back()->right = nullptr;
    }
};
```

### 解法说明

首先通过 `dfs` 对原二叉树进行“根、左、右”的前序遍历，并按顺序保存每个节点的地址。遍历完成后，数组 `v` 中的节点顺序就是展开后链表的顺序。随后依次把每个节点的 `left` 置为空，并让 `right` 指向数组中的下一个节点。最后一个节点的左右指针都置为空。

该实现只重新连接原树中的节点，没有创建新的结果节点，满足原地修改节点结构的要求。

### 复杂度

- 时间复杂度：`O(n)`，前序遍历和重新连接各处理每个节点一次
- 空间复杂度：`O(n)`，数组保存全部节点；递归栈最坏也可能达到 `O(n)`

> 如果同一个 `Solution` 对象可能多次调用 `flatten`，应在遍历前执行 `v.clear()`，避免保留上一次调用的节点。进阶做法可以寻找当前节点左子树的最右节点并原地接入右子树，在 `O(n)` 时间内将额外空间优化为 `O(1)`。

---

## 560. 和为 K 的子数组

- 难度：中等
- 题目链接：[LeetCode - 和为 K 的子数组](https://leetcode.cn/problems/subarray-sum-equals-k/description/?envType=study-plan-v2&envId=top-100-liked)

### 题目描述

给定一个整数数组 `nums` 和整数 `k`，统计并返回数组中元素和等于 `k` 的连续非空子数组数量。

### 示例

```text
输入：nums = [1,1,1], k = 2
输出：2
```

```text
输入：nums = [1,2,3], k = 3
输出：2
```

### 约束

- `1 <= nums.length <= 2 * 10^4`
- `-1000 <= nums[i] <= 1000`
- `-10^7 <= k <= 10^7`

### 做法一：前缀和 + 双重枚举

```cpp
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
```

#### 解法说明

把原数组转换为从下标 `1` 开始的数组 `a`，并计算前缀和 `sum[i]`。区间 `[i, j]` 的元素和可以通过 `sum[j] - sum[i - 1]` 在 `O(1)` 时间内得到。双重循环枚举所有起点和终点，统计区间和等于 `k` 的数量。

#### 复杂度

- 时间复杂度：`O(n^2)`，枚举所有连续子数组
- 空间复杂度：`O(n)`，使用数组保存转换后的数据和前缀和

> 这段原代码没有初始化 `sum[0]`，第一次计算 `sum[1]` 时会读取未初始化值，产生未定义行为。需要在计算前缀和之前增加 `sum[0] = 0;`。两个长度为 `200005` 的局部数组也会占用较大的栈空间，可以改用按输入长度分配的 `vector<int>`。

### 做法二：前缀和 + 哈希表

```cpp
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
```

#### 解法说明

遍历数组时，`sum` 表示当前位置的前缀和。如果此前出现过前缀和 `sum - k`，那么从这些历史位置的下一个元素到当前位置形成的子数组之和都等于 `k`，因此将其出现次数累加到答案。随后再记录当前前缀和。

初始化 `mp[0] = 1` 用于统计从数组下标 `0` 开始、元素和恰好等于 `k` 的子数组。必须先查询 `sum - k` 再记录当前 `sum`，才能保证统计的是非空子数组。

#### 复杂度

- 时间复杂度：平均 `O(n)`，每个元素进行常数次哈希表操作
- 空间复杂度：`O(n)`，最坏情况下保存 `n + 1` 个不同的前缀和

第二种做法避免枚举所有区间，是本题更适合的实现。

---

## 347. 前 K 个高频元素

- 难度：中等
- 题目链接：[LeetCode - 前 K 个高频元素](https://leetcode.cn/problems/top-k-frequent-elements/description/?envType=study-plan-v2&envId=top-100-liked)

### 题目描述

给定一个整数数组 `nums` 和整数 `k`，返回数组中出现频率最高的前 `k` 个元素。答案可以按任意顺序返回，题目保证前 `k` 个高频元素的集合唯一。

### 示例

```text
输入：nums = [1,1,1,2,2,3], k = 2
输出：[1,2]
```

```text
输入：nums = [1], k = 1
输出：[1]
```

```text
输入：nums = [1,2,1,2,1,2,3,1,3,2], k = 2
输出：[1,2]
```

### 约束

- `1 <= nums.length <= 10^5`
- `-10^4 <= nums[i] <= 10^4`
- `1 <= k <= nums` 中不同元素的数量
- 题目保证答案集合唯一

### 我的代码

```cpp
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
```

### 解法说明

首先使用 `mp` 统计每个元素的出现次数。随后建立反向映射 `mp1`，将出现次数作为键，把具有相同频率的元素放入同一个数组。由于任意元素的出现次数不会超过数组长度 `10^5`，最后从频率 `100000` 开始向下扫描，每遇到一个频率桶就把其中元素加入答案，并相应减少还需要选择的数量，直到得到前 `k` 个高频元素。

题目保证答案集合唯一，因此不会出现截止频率上的并列元素导致必须从同一频率桶中只选择一部分的情况。

### 复杂度

设不同元素数量为 `u`，不同频率数量为 `d`，扫描的最大频率为 `F = 10^5`：

- 时间复杂度：`O(n log u + u log d + F)`，主要来自两个 `std::map` 的查询和插入
- 空间复杂度：`O(u)`，保存元素频率和反向频率桶

> 该实现最坏情况下仍可能达到 `O(n log n)`，不满足题目的线性时间进阶要求。可以使用 `unordered_map` 在平均 `O(n)` 时间内统计频率，再创建长度为 `n + 1` 的桶数组，以频率作为下标从高到低收集元素，从而实现平均 `O(n)` 时间和 `O(n)` 空间；也可以使用大小为 `k` 的小顶堆实现 `O(n log k)`。

---

## 279. 完全平方数

- 难度：中等
- 题目链接：[LeetCode - 完全平方数](https://leetcode.cn/problems/perfect-squares/description/?envType=study-plan-v2&envId=top-100-liked)

### 题目描述

给定一个整数 `n`，返回和为 `n` 所需的完全平方数的最少数量。完全平方数是某个整数与自身相乘得到的数，例如 `1`、`4`、`9` 和 `16`。

### 示例

```text
输入：n = 12
输出：3
解释：12 = 4 + 4 + 4
```

```text
输入：n = 13
输出：2
解释：13 = 4 + 9
```

### 约束

- `1 <= n <= 10^4`

### 我的代码

```cpp
class Solution {
public:
    int numSquares(int n) {
        vector<int> dp(n + 1, INT_MAX);

        dp[0] = 0;

        for(int i = 1; i * i <= n; i++){
            int x = i * i;

            for(int j = x; j <= n; j++){
                dp[j] = min(dp[j], dp[j - x] + 1);
            }
        }

        return dp[n];
    }
};
```

### 解法说明

将每个不超过 `n` 的完全平方数看作一种可以重复选择的物品，把问题转换为完全背包。`dp[j]` 表示组成整数 `j` 所需的最少完全平方数数量，初始时只有 `dp[0] = 0`，其余状态设为无穷大。

枚举平方数 `x = i * i` 后，从小到大遍历 `j`，使用状态转移：

```text
dp[j] = min(dp[j], dp[j - x] + 1)
```

内层循环从小到大遍历，使本轮刚更新的状态可以继续参与后续转移，因此同一个平方数能够被重复选择，符合完全背包的特点。平方数 `1` 会先让所有状态变为可达，因此后续执行 `dp[j - x] + 1` 不会对 `INT_MAX` 加一。

### 复杂度

- 时间复杂度：`O(n * sqrt(n))`，枚举约 `sqrt(n)` 个平方数，每个平方数最多遍历 `n` 个状态
- 空间复杂度：`O(n)`，使用一维动态规划数组

---

## 322. 零钱兑换

- 难度：中等
- 题目链接：[LeetCode - 零钱兑换](https://leetcode.cn/problems/coin-change/description/?envType=study-plan-v2&envId=top-100-liked)

### 题目描述

给定一个整数数组 `coins` 表示不同面额的硬币，以及整数 `amount` 表示目标金额。每种硬币可以使用任意次，返回凑成目标金额所需的最少硬币数量；如果无法组成该金额，则返回 `-1`。

### 示例

```text
输入：coins = [1,2,5], amount = 11
输出：3
解释：11 = 5 + 5 + 1
```

```text
输入：coins = [2], amount = 3
输出：-1
```

```text
输入：coins = [1], amount = 0
输出：0
```

### 约束

- `1 <= coins.length <= 12`
- `1 <= coins[i] <= 2^31 - 1`
- `0 <= amount <= 10^4`

### 我的代码

```cpp
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount + 1, amount + 1);
        dp[0] = 0;
        int n = coins.size();
        sort(coins.begin(), coins.end());
        for(int i = 0;i < coins.size();i++){
            for(int j = coins[i];j <= amount;j++){
                dp[j] = min(dp[j], dp[j - coins[i]] + 1);
            }
        }
        if(dp[amount] == amount + 1)
            return -1;
        return dp[amount];
    }
};
```

### 解法说明

将每种硬币看作可以无限次使用的物品，使用完全背包动态规划。`dp[j]` 表示组成金额 `j` 所需的最少硬币数量。`dp[0] = 0`，其余状态初始化为不可能成为合法答案的哨兵值 `amount + 1`。

枚举面额 `coins[i]` 时，从该面额开始正序遍历金额，并执行：

```text
dp[j] = min(dp[j], dp[j - coins[i]] + 1)
```

金额正序遍历允许本轮更新后的状态继续使用同一种硬币，因此每种硬币可以选择任意次。最终如果 `dp[amount]` 仍为哨兵值，说明目标金额不可达，返回 `-1`。

### 复杂度

设硬币种类数为 `m`：

- 时间复杂度：`O(m log m + m * amount)`，包括排序和动态规划
- 空间复杂度：`O(amount)`，使用一维动态规划数组

> 动态规划只依赖硬币面额，不要求 `coins` 有序，因此这里的 `sort` 可以省略，也能避免修改输入数组；变量 `n` 没有被使用，可以删除。省略排序后时间复杂度为 `O(m * amount)`。

---

## 139. 单词拆分

- 难度：中等
- 题目链接：[LeetCode - 单词拆分](https://leetcode.cn/problems/word-break/description/?envType=study-plan-v2&envId=top-100-liked)

### 题目描述

给定字符串 `s` 和字符串列表 `wordDict`。如果可以使用字典中的一个或多个单词拼接出完整的 `s`，则返回 `true`，否则返回 `false`。字典中的单词不要求全部使用，并且每个单词可以重复使用。

### 示例

```text
输入：s = "leetcode", wordDict = ["leet","code"]
输出：true
解释："leetcode" 可以由 "leet" 和 "code" 拼接得到。
```

```text
输入：s = "applepenapple", wordDict = ["apple","pen"]
输出：true
解释：字典中的单词可以重复使用。
```

```text
输入：s = "catsandog", wordDict = ["cats","dog","sand","and","cat"]
输出：false
```

### 约束

- `1 <= s.length <= 300`
- `1 <= wordDict.length <= 1000`
- `1 <= wordDict[i].length <= 20`
- `s` 和 `wordDict[i]` 仅由小写英文字母组成
- `wordDict` 中的字符串互不相同

### 我的代码

```cpp
class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        int n = s.size();

        bool dp[305] = {};
        dp[0] = true;

        map<string, int> mp;

        for (int i = 0; i < wordDict.size(); i++) {
            mp[wordDict[i]] = 1;
        }

        for (int i = 1; i <= n; i++) {
            for (int j = 0; j < i; j++) {
                string str = s.substr(j, i - j);

                if (mp[str] && dp[j]) {
                    dp[i] = true;
                }

                if (dp[i])
                    break;
            }
        }

        return dp[n];
    }
};
```

### 解法说明

`dp[i]` 表示字符串前 `i` 个字符组成的前缀 `s[0, i)` 是否能够由字典单词拼接得到。空前缀不需要任何单词，因此初始化 `dp[0] = true`。

对于每个前缀终点 `i`，枚举最后一个单词的起点 `j`。如果前缀 `s[0, j)` 已经可以拆分，并且子串 `s[j, i)` 存在于字典中，那么 `dp[i]` 就可以设为 `true`。一旦找到合法分割位置，就提前结束当前内层循环。最终返回 `dp[n]`。

### 复杂度

代码枚举 `O(n^2)` 个分割区间，而 `substr` 会复制最长 `O(n)` 个字符；`std::map` 的字符串查询还包含树查找和字符串比较。因此：

- 时间复杂度：最坏可达 `O(n^3 log q)`，`q` 为执行过程中 `map` 中的键数量
- 空间复杂度：最坏可达 `O(n^3)` 个字符，因为缺失的子串也可能被插入 `map`；另有 `O(n)` 的动态规划状态

> `mp[str]` 在 `str` 不存在时会向 `map` 插入一个值为 `0` 的新键，而且它在 `dp[j]` 之前被求值，所以许多无用子串也会被保存。建议先判断 `dp[j]`，再使用 `mp.find(str) != mp.end()`；也可以改用 `unordered_set<string>`，并利用字典单词最大长度为 `20` 的约束，只枚举可能的单词长度，从而显著减少时间和内存开销。

---

## 300. 最长递增子序列

- 难度：中等
- 题目链接：[LeetCode - 最长递增子序列](https://leetcode.cn/problems/longest-increasing-subsequence/description/?envType=study-plan-v2&envId=top-100-liked)

### 题目描述

给定一个整数数组 `nums`，返回其中最长严格递增子序列的长度。子序列可以删除原数组中的部分元素，但不能改变保留元素之间的相对顺序。

### 示例

```text
输入：nums = [10,9,2,5,3,7,101,18]
输出：4
解释：最长递增子序列可以是 [2,3,7,101]。
```

```text
输入：nums = [0,1,0,3,2,3]
输出：4
```

```text
输入：nums = [7,7,7,7,7,7,7]
输出：1
```

### 约束

- `1 <= nums.length <= 2500`
- `-10^4 <= nums[i] <= 10^4`

### 我的代码

```cpp
class Solution {
public:
    int dp[2505];
    int n;
    int a[2505];

    int lengthOfLIS(vector<int>& nums) {
        n = nums.size();
        for(int i =0;i < nums.size();i++) a[i + 1] = nums[i];
        int maxn = 0;
        for(int i = 1;i <= n;i++){
            dp[i] = 1;
            for(int j = 1;j < i;j++){
                if(a[j] < a[i]) dp[i] = max(dp[i], dp[j] + 1);
            }
        }
        for(int i = 1;i <= n;i++) {
            // cout << dp[i] << endl;
            maxn = max(maxn, dp[i]);
        }
        return maxn;
    }
};
```

### 解法说明

先把输入复制到从下标 `1` 开始的数组 `a`。`dp[i]` 表示以第 `i` 个元素 `a[i]` 结尾的最长严格递增子序列长度，单独选择当前元素时长度为 `1`。

对于每个位置 `i`，枚举它前面的所有位置 `j`。当 `a[j] < a[i]` 时，可以把当前元素接在以 `a[j]` 结尾的递增子序列后面，因此执行：

```text
dp[i] = max(dp[i], dp[j] + 1)
```

最长递增子序列不一定以最后一个元素结尾，所以最后需要在所有 `dp[i]` 中取最大值。

### 复杂度

- 时间复杂度：`O(n^2)`，每个位置枚举它之前的所有元素
- 空间复杂度：`O(n)`，使用数组 `a` 和动态规划数组 `dp`

> 进阶做法可以维护数组 `tails`，其中 `tails[len - 1]` 表示长度为 `len` 的递增子序列能够取得的最小末尾值。对每个元素使用 `lower_bound` 找到替换位置，可将时间复杂度优化为 `O(n log n)`，空间复杂度保持 `O(n)`。

---

## 152. 乘积最大子数组

- 难度：中等
- 题目链接：[LeetCode - 乘积最大子数组](https://leetcode.cn/problems/maximum-product-subarray/description/?envType=study-plan-v2&envId=top-100-liked)

### 题目描述

给定一个整数数组 `nums`，找出其中乘积最大的非空连续子数组，并返回该子数组的乘积。题目保证任意子数组的乘积都在 32 位整数范围内。

### 示例

```text
输入：nums = [2,3,-2,4]
输出：6
解释：连续子数组 [2,3] 的乘积最大，为 6。
```

```text
输入：nums = [-2,0,-1]
输出：0
解释：[-2,-1] 不是连续子数组。
```

### 约束

- `1 <= nums.length <= 2 * 10^4`
- `-10 <= nums[i] <= 10`
- 任意子数组的乘积都在 32 位整数范围内

### 我的代码

```cpp
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();

        vector<int> mx(n);
        vector<int> mn(n);

        mx[0] = nums[0];
        mn[0] = nums[0];

        int ans = nums[0];

        for(int i = 1; i < n; i++){
            mx[i] = max({
                nums[i],
                mx[i - 1] * nums[i],
                mn[i - 1] * nums[i]
            });

            mn[i] = min({
                nums[i],
                mx[i - 1] * nums[i],
                mn[i - 1] * nums[i]
            });

            ans = max(ans, mx[i]);
        }

        return ans;
    }
};
```

### 解法说明

`mx[i]` 表示以 `nums[i]` 结尾的连续子数组能够取得的最大乘积，`mn[i]` 表示对应的最小乘积。处理当前元素时有三种选择：只选择 `nums[i]` 重新开始一个子数组；接在此前最大乘积后面；或接在此前最小乘积后面。

必须同时保存最小乘积，因为当 `nums[i]` 为负数时，此前的最小负乘积乘以当前负数，可能变成新的最大正乘积。数字 `0` 则可以通过“只选择当前元素”自然地中断此前区间。每轮使用 `mx[i]` 更新全局答案。

### 复杂度

- 时间复杂度：`O(n)`，每个元素只处理一次
- 空间复杂度：`O(n)`，使用两个动态规划数组

> 当前状态只依赖前一个位置的最大和最小乘积，可以使用两个滚动变量代替数组，将额外空间复杂度优化为 `O(1)`。更新时需要先保存上一轮的两个值，避免新状态覆盖旧状态。

---

## 416. 分割等和子集

- 难度：中等
- 题目链接：[LeetCode - 分割等和子集](https://leetcode.cn/problems/partition-equal-subset-sum/description/?envType=study-plan-v2&envId=top-100-liked)

### 题目描述

给定一个只包含正整数的非空数组 `nums`，判断能否将它分割为两个子集，使两个子集的元素和相等。

### 示例

```text
输入：nums = [1,5,11,5]
输出：true
解释：可以分割为 [1,5,5] 和 [11]。
```

```text
输入：nums = [1,2,3,5]
输出：false
```

### 约束

- `1 <= nums.length <= 200`
- `1 <= nums[i] <= 100`

### 我的代码

```cpp
class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        for(auto &x : nums){
            sum += x;
        }

        if(sum % 2 != 0) return false;
        int val = sum / 2;
        vector<bool> dp(val + 1, false);
        dp[0] = true;

        for(int i = 0;i < nums.size();i++){
            for(int j= val;j >= nums[i];j--){
                dp[j] = dp[j] || dp[j - nums[i]];
            }
        }
        return dp[val];
    }
};
```

### 解法说明

如果数组总和为奇数，不可能平均分成两个整数和相同的子集，直接返回 `false`。当总和为偶数时，问题等价于：能否从数组中选择一部分元素，使其和恰好为总和的一半 `val`。

使用 0-1 背包动态规划，`dp[j]` 表示能否使用已经处理过的元素凑出和 `j`。空集合可以凑出 `0`，所以初始化 `dp[0] = true`。对于当前元素 `nums[i]`，状态转移为：

```text
dp[j] = dp[j] || dp[j - nums[i]]
```

金额 `j` 必须从大到小遍历，确保当前元素在本轮最多使用一次；如果从小到大遍历，刚更新的状态会再次参与转移，使同一个元素被重复选择，变成完全背包。最终返回 `dp[val]`。

### 复杂度

设数组长度为 `n`，全部元素之和为 `S`：

- 时间复杂度：`O(n * S)`，目标容量为 `S / 2`，常数因子省略
- 空间复杂度：`O(S)`，使用长度为 `S / 2 + 1` 的一维状态数组

---

## 1143. 最长公共子序列

- 难度：中等
- 题目链接：[LeetCode - 最长公共子序列](https://leetcode.cn/problems/longest-common-subsequence/description/?envType=study-plan-v2&envId=top-100-liked)

### 题目描述

给定两个字符串 `text1` 和 `text2`，返回它们最长公共子序列的长度；如果不存在公共子序列，则返回 `0`。子序列可以删除原字符串中的部分字符，但不能改变保留字符的相对顺序。

### 示例

```text
输入：text1 = "abcde", text2 = "ace"
输出：3
解释：最长公共子序列为 "ace"。
```

```text
输入：text1 = "abc", text2 = "abc"
输出：3
```

```text
输入：text1 = "abc", text2 = "def"
输出：0
```

### 约束

- `1 <= text1.length, text2.length <= 1000`
- `text1` 和 `text2` 仅由小写英文字母组成

### 我的代码

```cpp
class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int n = text1.size();
        int m = text2.size();

        int dp[1005][1005] = {};

        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= m; j++){
                if(text1[i - 1] == text2[j - 1]){
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                }else{
                    dp[i][j] = max(
                        dp[i - 1][j],
                        dp[i][j - 1]
                    );
                }
            }
        }

        return dp[n][m];
    }
};
```

### 解法说明

`dp[i][j]` 表示 `text1` 的前 `i` 个字符与 `text2` 的前 `j` 个字符能够形成的最长公共子序列长度。数组初始化为 `0`，自然覆盖了任意一方为空字符串的边界状态。

当 `text1[i - 1] == text2[j - 1]` 时，可以把这个相同字符接到两个更短前缀的最长公共子序列后面：

```text
dp[i][j] = dp[i - 1][j - 1] + 1
```

当两个字符不同时，当前公共子序列不能同时选择它们，因此分别尝试忽略 `text1` 或 `text2` 的当前字符，并取较大值：

```text
dp[i][j] = max(dp[i - 1][j], dp[i][j - 1])
```

最终 `dp[n][m]` 就是两个完整字符串的最长公共子序列长度。

### 复杂度

- 时间复杂度：`O(n * m)`，计算二维状态表中的每个位置
- 空间复杂度：`O(n * m)`，保存完整二维动态规划数组

> 当前局部数组约占 4 MB 栈空间，在栈限制较小的环境中可以改为堆上的 `vector` 或类成员数组。由于每一行只依赖上一行和当前行左侧状态，可以使用滚动数组将空间复杂度优化为 `O(min(n, m))`。

---

## 62. 不同路径

- 难度：中等
- 题目链接：[LeetCode - 不同路径](https://leetcode.cn/problems/unique-paths/description/?envType=study-plan-v2&envId=top-100-liked)

### 题目描述

一个机器人位于 `m x n` 网格的左上角，每次只能向下或向右移动一步。求它到达网格右下角共有多少条不同路径。

### 示例

```text
输入：m = 3, n = 7
输出：28
```

```text
输入：m = 3, n = 2
输出：3
解释：三条路径分别为右下下、下下右和下右下。
```

### 约束

- `1 <= m, n <= 100`
- 题目保证答案不超过 `2 * 10^9`

### 我的代码

```cpp
class Solution {
public:
    int uniquePaths(int m, int n) {
        int dp[105][105] = {};
        for(int i = 1;i <= m;i++) dp[i][1] = 1;
        for(int i = 1;i <= n;i++) dp[1][i] = 1;
        for(int i = 1;i <= m;i++){
            for(int j = 1;j <= n;j++){
                if(i != 1 || j != 1) dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
            }
        }
        return dp[m][n];
    }
};
```

### 解法说明

`dp[i][j]` 表示从左上角走到第 `i` 行、第 `j` 列位置的不同路径数量。第一列只能一直向下到达，第一行只能一直向右到达，因此它们的路径数都初始化为 `1`。

对于其他位置，机器人最后一步只能从上方或左方走来，所以状态转移为：

```text
dp[i][j] = dp[i - 1][j] + dp[i][j - 1]
```

条件 `i != 1 || j != 1` 只会排除起点 `(1, 1)`，避免把已初始化的起点覆盖为 `0`。最终返回右下角状态 `dp[m][n]`。

### 复杂度

- 时间复杂度：`O(m * n)`，遍历整个网格
- 空间复杂度：`O(m * n)`，使用二维动态规划数组

> 每个状态只依赖上一行的同一列和当前行的前一列，可以使用一维滚动数组将空间复杂度优化为 `O(n)`；如果选择较短的网格维度作为数组长度，则可以进一步写成 `O(min(m, n))`。

---

## 64. 最小路径和

- 难度：中等
- 题目链接：[LeetCode - 最小路径和](https://leetcode.cn/problems/minimum-path-sum/description/?envType=study-plan-v2&envId=top-100-liked)

### 题目描述

给定一个包含非负整数的 `m x n` 网格 `grid`，找出一条从左上角到右下角的路径，使路径上所有数字的总和最小。每次只能向下或向右移动一步。

### 示例

```text
输入：grid = [[1,3,1],[1,5,1],[4,2,1]]
输出：7
解释：路径 1→3→1→1→1 的总和最小。
```

```text
输入：grid = [[1,2,3],[4,5,6]]
输出：12
```

### 约束

- `m == grid.length`
- `n == grid[i].length`
- `1 <= m, n <= 200`
- `0 <= grid[i][j] <= 200`

### 我的代码

```cpp
class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int dp[205][205];
        memset(dp, 0x7f, sizeof dp);
        dp[1][1] = grid[0][0];
        int m = grid.size();
        int n = grid[0].size();
        for(int i = 1;i <= grid.size();i++){
            for(int j = 1;j <= grid[i - 1].size();j++){
                dp[i][j] = min(dp[i][j], dp[i - 1][j] + grid[i - 1][j - 1]);
                dp[i][j] = min(dp[i][j], dp[i][j - 1] + grid[i - 1][j - 1]);
            }
        }
        return dp[m][n];
    }
};
```

### 解法说明

`dp[i][j]` 表示走到原网格位置 `grid[i - 1][j - 1]` 时能够取得的最小路径和。先使用 `memset(dp, 0x7f, ...)` 把整个状态表填充为一个很大的正数，使网格外侧的第 `0` 行和第 `0` 列不能成为有效转移来源，并将起点 `dp[1][1]` 初始化为 `grid[0][0]`。

每个位置只能从上方或左方到达，因此依次执行：

```text
dp[i][j] = min(
    dp[i - 1][j],
    dp[i][j - 1]
) + grid[i - 1][j - 1]
```

原代码把这个公式拆成两次 `min` 更新。处理起点时，它已经是 `grid[0][0]`，与两个哨兵状态相加得到的值更大，因此起点不会被覆盖。最终返回 `dp[m][n]`。

### 复杂度

- 时间复杂度：`O(m * n)`，每个网格位置处理一次
- 空间复杂度：`O(m * n)`，使用二维动态规划数组

> 状态只依赖上一行和当前行的左侧位置，可以使用一维滚动数组把空间复杂度优化为 `O(n)`；如果允许修改输入，也可以直接在 `grid` 中累计最小路径和，将额外空间复杂度优化为 `O(1)`。
