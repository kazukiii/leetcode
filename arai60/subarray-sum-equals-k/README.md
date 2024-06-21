## 考察
- 初見の問題
- nums[i] >= 0 なら sliding window でやりたいところだが負の数もあり
- 区間和を高速で計算したいので累積和を使用
- 方針
    - 累積和 + 区間全探索
        - time: O(n^2), space: O(n)
        - nums.length <= 2 * 10^4 なので通りそうだが最適解ではなさそう
        - 通った -> `step1_brute_force.cpp`
- もう少し最適化を考えたい
- 方針2
    - 引き算だけど、two sumの要領でいけるはず
    - あるインデックスより前の累積和の度数分布のようなものを追加メモリで持ちたい
    - time: O(n), space: O(n^2)
- MLE
```cpp
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> prefix_sum(n + 1, 0);
        vector<unordered_map<int, int>> prefix_sum_count(n + 1, {{0, 1}});
        for (int i = 0; i < n; i++) {
            prefix_sum[i + 1] = prefix_sum[i] + nums[i];
            prefix_sum_count[i + 1] = prefix_sum_count[i];
            prefix_sum_count[i + 1][prefix_sum[i + 1]]++;
        }

        int answer = 0;
        for (int i = 1; i <= n; i++) {
            int difference = prefix_sum[i] - k;
            answer += prefix_sum_count[i - 1][difference];
        }
        return answer;
    }
};
```
- もう少し考える
- 方針3
    - i -> i + 1 への遷移しかないので、in-place DPの要領で次元を一つ消せそう
    - 通った。難しかった。
    - time: O(n), space: O(n)

## Step2
- Solutionsを覗いてみた
    - 方針はだいたい良さそう
- 変数名を見直し
    - answer -> total
    - prefix_sum_count -> prefix_sum_to_count
- 他の人のPRを検索
    - numpyにはcumsumがある
        - https://github.com/TORUS0818/leetcode/pull/18#discussion_r1646398612
    - inclusiveな範囲を表現する際には、変数名はfirst-lastが良い
        - https://github.com/goto-untrapped/Arai60/pull/28#discussion_r1642960547
    - 累積和についての小田さんのメモ
        - https://github.com/Exzrgs/LeetCode/pull/25#discussion_r1640727899
        - https://discord.com/channels/1084280443945353267/1183683738635346001/1192145962479665304
    - 類題
        - https://github.com/SuperHotDogCat/coding-interview/pull/29#issuecomment-2169284348
        - https://leetcode.com/problems/subarray-sums-divisible-by-k/description/

## Step3
- 1回目: 1m38s
- 2回目: 1m30s
- 3回目: 1m29s
