## 考察
- 過去に解いたことあり
- 常にk番目に大きい要素を高速に取り出せる状態にしておきたい
- 各クエリでkが固定なところもポイントだと思う
- 方針は4つ思い浮かぶ
    - ソート済みnumsを保つ
        - 二分探索で挿入ポイントを探して、insertする(insertにO(n)かかる)
        - 初期化: O(n log n), 各クエリ: O(n)
    - 最小ヒープを使う
        - ヒープのサイズをkに保つ
        - 初期化: O(n log k), 各クエリ: O(log k)
    - fenwick tree上の二分探索(もしくはsegment tree上の二分探索)
        - -10^4 <= nums[i] <= 10^4 かつ -10^4 <= val <= 10^4 なので、種類としては高々2 * 10^4 + 1
        - 各数字が何回現れたかを管理できる
        - kが各クエリで変わるときは、この方法になると思う(今回はk固定なのでスキップ)
        - 初期化: O(n log n), 各クエリ: O(log n)
    - 平衡二分探索木
        - たぶん最終手段だと思う
        - Pythonにはライブラリはない、一から実装することになりそう(かなり大変そうなイメージ、実装したことはない)
- 最も効率の良い最小ヒープでやる
- あとは実装

## Step1
- 最小ヒープで実装
- time: O(n log k), space: O(k)

## Step2
- 他の人のPRを検索してみた
- Pythonにはheappushpopというのがあるらしい
    - Ref. https://github.com/kagetora0924/leetcode-grind/pull/9#discussion_r1633996701
    - heappush()とheappop()を個別に呼び出すよりも効率が良い
    - `Push item on the heap, then pop and return the smallest item from the heap. The combined action runs more efficiently than heappush() followed by a separate call to heappop().`
        - Ref. https://docs.python.org/3/library/heapq.html#heapq.heappushpop
- heappushpopを使ってみた

## Step3
- 1回目: 1m46s
- 2回目: 1m51s
- 3回目: 1m42s
