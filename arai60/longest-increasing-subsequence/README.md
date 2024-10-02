## Step1
- 有名問題
- O(n^2) のDPが思いつく
    - 今回は nums.length <= 2500 なので十分そう

- Follow up として O(n log n) で解けるかとある
    - プログラミングコンテストチャレンジブックで二分探索による解法を見たことがあるが完全に忘れてしまった
        - Step2で復習する
    - セグメント木による解法もあるが、セグメント木を何も見ずに書ける自信なし、、
        - Step2でソラで書けるように練習する
        - Step1ではセグメント木をライブラリとして使ってやってみる
            - https://github.com/not522/ac-library-python/blob/master/atcoder/segtree.py
            - ここから拾ってくる

- まずは、普通の bottom-up DP で
    - max_lengths[i][j] := i番目(1-indexed)までの subproblem を考えたとき、増加部分列が nums[j] で終わるような最大の長さ とする
```python
class Solution:
    def lengthOfLIS(self, nums: List[int]) -> int:
        n = len(nums)
        max_lengths = [[0] * n for _ in range(n + 1)]
        # initial conditions
        for i in range(n):
            max_lengths[i + 1][i] = 1

        for i in range(1, n):
            for j in range(i):
                if nums[j] < nums[i]:
                    # nums[i] を選ぶ
                    max_lengths[i + 1][i] = max(
                        max_lengths[i + 1][i],
                        max_lengths[i][j] + 1,
                    )
                # nums[i] を選ばない
                max_lengths[i + 1][j] = max(
                    max_lengths[i + 1][j],
                    max_lengths[i][j],
                )
        return max(max_lengths[-1])
```

- 例によって、in-place化
    - i -> i + 1 の遷移かつ一点更新のみ
    - time: O(n^2), space: O(n)
```python
class Solution:
    def lengthOfLIS(self, nums: List[int]) -> int:
        n = len(nums)
        max_lengths = [1] * n
        for i in range(1, n):
            for j in range(i):
                if nums[j] >= nums[i]: continue
                max_lengths[i] = max(max_lengths[i], max_lengths[j] + 1)
        return max(max_lengths)
```

- top-down DP
    - 今回のパターンではあまり読みやすくなったような感じはしない
```python
class Solution:
    def lengthOfLIS(self, nums: List[int]) -> int:
        n = len(nums)

        @cache
        def max_lengths(i: int) -> int:
            max_length = 1
            for j in range(i):
                if nums[j] < nums[i]:
                    max_length = max(max_length, max_lengths(j) + 1)
            return max_length

        return max(max_lengths(i) for i in range(n))
```

- セグメント木（コピペして使用）
    - 参照) https://atcoder.github.io/ac-library/production/document_en/segtree.html
    - time: O(n log n), space: O(n)
```python
import typing


class Solution:
    def lengthOfLIS(self, nums: List[int]) -> int:
        sorted_nums = list(set(nums))
        sorted_nums.sort()

        # モノイドを定義
        def binary_operator(x: int, y: int) -> int:
            return max(x, y)

        identity_element = 0

        max_lengths = SegTree(binary_operator, identity_element, len(sorted_nums))
        ans = 0
        for num in nums:
            # 座標圧縮
            pos = bisect_left(sorted_nums, num)
            max_length_so_far = max_lengths.prod(0, pos)
            max_lengths.set(pos, max_length_so_far + 1)
            ans = max(ans, max_length_so_far + 1)
        return ans


class SegTree:
    def __init__(
        self,
        op: typing.Callable[[typing.Any, typing.Any], typing.Any],
        e: typing.Any,
        v: typing.Union[int, typing.List[typing.Any]],
    ) -> None:
        self._op = op
        self._e = e

        if isinstance(v, int):
            v = [e] * v

        self._n = len(v)
        self._log = self._ceil_pow2(self._n)
        self._size = 1 << self._log
        self._d = [e] * (2 * self._size)

        for i in range(self._n):
            self._d[self._size + i] = v[i]
        for i in range(self._size - 1, 0, -1):
            self._update(i)

    def set(self, p: int, x: typing.Any) -> None:
        assert 0 <= p < self._n

        p += self._size
        self._d[p] = x
        for i in range(1, self._log + 1):
            self._update(p >> i)

    def prod(self, left: int, right: int) -> typing.Any:
        assert 0 <= left <= right <= self._n
        sml = self._e
        smr = self._e
        left += self._size
        right += self._size

        while left < right:
            if left & 1:
                sml = self._op(sml, self._d[left])
                left += 1
            if right & 1:
                right -= 1
                smr = self._op(self._d[right], smr)
            left >>= 1
            right >>= 1

        return self._op(sml, smr)

    def _update(self, k: int) -> None:
        self._d[k] = self._op(self._d[2 * k], self._d[2 * k + 1])

    @staticmethod
    def _ceil_pow2(n: int) -> int:
        x = 0
        while (1 << x) < n:
            x += 1

        return x
```

## Step2
- 二分探索による高速化
    - かなり頭が混乱した
    - 覚えておかないと厳しい印象
```python
class Solution:
    def lengthOfLIS(self, nums: List[int]) -> int:
        min_end_values_of_subsequcnce = [math.inf] * len(nums)
        for num in nums:
            pos = bisect_left(min_end_values_of_subsequcnce, num)
            min_end_values_of_subsequcnce[pos] = num
        return bisect_left(min_end_values_of_subsequcnce, math.inf)
```

- セグメント木を自力で
    - なにをやっているかをちゃんと理解すれば案外スラスラ書けた気がする
    - 区間更新とかもあるらしいが今はやらない
```python
class Solution:
    def lengthOfLIS(self, nums: List[int]) -> int:
        unique_nums = list(set(nums))
        sorted_nums = sorted(unique_nums)

        max_lengths = SegTree()
        ans = 0
        for num in nums:
            pos = bisect_left(sorted_nums, num)
            max_lenghth_so_far = max_lengths.get_max(0, pos)
            max_lengths.set_value(pos, max_lenghth_so_far + 1)
            ans = max(ans, max_lenghth_so_far + 1)
        return ans


class SegTree:
    def __init__(self):
        # nums.length <= 2500 なので十分な長さ用意しておく
        self.n = 2 ** 12
        self.seg = [0] * (2 * self.n)

    def set_value(self, pos: int, value: int) -> None:
        pos += self.n
        self.seg[pos] = value
        # 親を全部更新
        pos //= 2
        while pos > 0:
            self.seg[pos] = max(self.seg[2 * pos], self.seg[2 * pos + 1])
            pos //= 2

    def get_max(self, query_left: int, query_right: int, seg_left: int = 0, seg_right: int = 2 ** 12, pos: int = 1) -> int:
        # クエリ範囲とセグメント範囲が全く被っていない場合 -> 単位元を返す
        if query_right <= seg_left or seg_right <= query_left: return 0

        # クエリ範囲がセグメント範囲を包含している場合 -> そのポジションの値を返す
        if query_left <= seg_left and seg_right <= query_right: return self.seg[pos]

        # それ以外 -> 子どもに任せる
        seg_mid = (seg_left + seg_right) // 2
        return max(
            self.get_max(query_left, query_right, seg_left, seg_mid, 2 * pos),
            self.get_max(query_left, query_right, seg_mid, seg_right, 2 * pos + 1),
        )
```

- 過去ログを参照
    - https://github.com/shining-ai/leetcode/pull/31
        >セグメントツリーと座標圧縮を使うのは、この問題を解くにあたっては指し過ぎだと思います。勉強のためと割り切って書くのは良いと思います。
    - https://github.com/Ryotaro25/leetcode_first60/pull/34
        >ソフトウェアエンジニアの常識から微妙に外れていると思います。知っている人は多いけれども、知らなくても別に動揺されないものです。
つまり、これを使ってできる高速化はできなくても構わないのですが、しかし、考える時にこれも知っていると、セグメントツリーを使わない方法を思いついたりするので、知っていてもいいかもしれません。
    - https://github.com/Yoshiki-Iwasa/Arai60/pull/46
        >ちなみにlisはlongest increasing subsequenceとは必ずしも一致しないですが、この命名でよいでしょうか？
たとえばnums = [10, 11, 12, 1, 2]を与えると、lisは[1, 2, 12]になると思います。実際には[1, 2, 12]という部分列を取ることはできません。
        - 命名は悩んだ。説明的にしようとするとどんどん長くなってしまう。。
            - `end_minimums_of_is`, `sub_seq_minimums`, `smallest_value_of_subseq` など候補
            - これらを考慮して `end_minimums_of_subsequence` が個人的に良さそう
    - https://github.com/fhiyo/leetcode/pull/32

## Step3
- 練習も兼ねて二分探索で
```python
class Solution:
    def lengthOfLIS(self, nums: List[int]) -> int:
        end_minimums_of_subsequence = [math.inf] * len(nums)
        ans = 0
        for num in nums:
            pos = bisect_left(end_minimums_of_subsequence, num)
            end_minimums_of_subsequence[pos] = num
            ans = max(ans, pos + 1)
        return ans
```
