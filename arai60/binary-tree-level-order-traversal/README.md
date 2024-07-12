## 考察
- 過去に解いたことあり
- 方針
    - BFS
        - BFSはlevelごとに見ていくのでシンプルに解ける
        - 実装としては、キューを1つ使う方法と2つ使う方法が考えられる
    - DFS
        - 一応、levelを追跡すればOK
        - でも、DFSでやるメリットはないと思われる
- まずは、BFSのキューを1つだけ用意する方法で実装

## Step1
- BFSで実装
- time: O(n), space: O(n)

## Step2
- キューを2つ用意する方法でも実装
    - `step2_bfs_two_queues.cpp`
- 特にキューである必要もないので、vector2つでも実装
    - `step2_bfs_two_vectors.cpp`
- 練習のためにDFSでも実装
    - `stpe2_dfs.cpp`
- 他の人のPRを検索
    - https://github.com/fhiyo/leetcode/pull/28
        - append_if_existsはいいなあと思った
    - https://github.com/Mike0121/LeetCode/pull/7
        - currentについて
            - https://github.com/Mike0121/LeetCode/pull/7#discussion_r1587660995
            - たしかに `level_values` だけでも通じるかも

## Step3
- 1回目: 3m27s
- 2回目: 3m12s
- 3回目: 3m05s
