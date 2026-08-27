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
