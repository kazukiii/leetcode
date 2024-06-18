## 考察
- 過去に解いたことあり
- 方針
    - 積集合をとる(Pythonだと、setに変換して集合演算)
        - time: O(n + m), space: O(n + m)
        - n: len(nums1), m: len(nums2)
    - 片方をHashSetにしてループ処理
        - 結果をユニークにして返す
        - time: O(n + m), space: O(n + m)
- 直感的な積集合をとる方針でやる
- あとは実装

## Step1
- 集合演算で実装
- time: O(n + m), space: O(n + m)

## Step2
- ほかの人のPRを検索してみた
- sortしてtwo pointersを使う方法もあるみたい
    - Ref. https://github.com/Mike0121/LeetCode/pull/30#discussion_r1641596790
    - そういえば昨日ちょうどソート済みの2つの配列のintersectionを活用する問題をやった
        - https://leetcode.com/problems/get-the-maximum-score/description/
    - もともとソート済みならO(min(n, m))なので速い
    - この手法でもやってみる
- この問題の場合は、ソートがボトルネックになる
- time: O(n log n + m log m), space: O(min(n, m))

## Step3
- 1回目: 22s
- 2回目: 21s
- 3回目: 22s

## Step4
- レビューを元に修正
- ワンライナーでも良さそうなので、一行で記述した
