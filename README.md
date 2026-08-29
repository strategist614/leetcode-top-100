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
