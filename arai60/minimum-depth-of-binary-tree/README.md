## 考察
- 初見の問題
- 昨日の問題が maximum depth だったのに対して minimum depth
- 方針
    - DFS
        - 帰りがけ
            - left subtreeとright subtreeのdepthのminを取って1を足して返却
            - 再帰の深さについて考える必要
            - 最大10^5のため、デフォルトのPythonの環境では厳しい(一応LeetCode上ならOK)
            - 帰りがけDFSを非再帰で書くのはつらい
        - 行きがけ
            - 全探索しながらleafのときに答えを更新
    - BFS
        - level順に見ていくので、leafが見つかったら答えをreturnしてOK
- 上記を考慮して、Step1はBFSでやる
- あとは実装

## Step1
- BFSで実装
- nodeがNoneのときにはキューに入れない実装もできるが、複雑度(if文)が2つ増えるためこちらの書き方を選択
- time: O(n), space: O(n)

## Step2
- 帰りがけDFSと行きがけDFSでも書いてみる
    - `step2_postorder_dfs.py`
    - `step2_preorder_dfs.py`
- 実装のしやすさでは再帰DFS
- 他の人のPRを検索してみる
    - BFSはキューを2つ作る書き方も主流みたい
        - https://github.com/fhiyo/leetcode/pull/24#discussion_r1648682841
        - この書き方はtorusさんのword ladderでのbidirectional bfsの解法のところでも見た
        - 前から順番に取り出せればいいのでキューである必要はなさそう
    - float('inf')について
        - https://github.com/fhiyo/leetcode/pull/24#discussion_r1648673169
    - is と == の違い
        - https://github.com/sakupan102/arai60-practice/pull/23#discussion_r1591177498

## Step3
- 1回目: 1m16s
- 2回目: 1m03s
- 3回目: 1m01s
