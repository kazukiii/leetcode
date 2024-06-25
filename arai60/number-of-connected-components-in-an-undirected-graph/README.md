## 考察
- 初見の問題
- Number of Islandsを一般のグラフにしたような問題
- 方針
    - DFS
    - BFS
    - Union Find
- Step1ではDFSでやってみる
- 再帰の深さは最大で2000
- あとは実装

## Step1
- DFSで実装
- time: O(n), space: O(n)

## Step2
- BFSでも実装
    - time: O(n), space: O(n)
- Union Findでも実装
    - 前回Union by sizeもやったので、path compressionのみ実装
    - time: O(n log n), space: O(n)
    - Class Data Members の命名については以下を参照した
        - https://google.github.io/styleguide/cppguide.html#Variable_Names

## Step3
- 1回目: 4m20s
- 2回目: 3m48s
- 3回目: 3m03s
