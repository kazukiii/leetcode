## 考察
- 初見の問題
- 問題設定は前回の Number of Islands とほぼ同じ
    - 連結成分のノードの数をカウントすればOK
- 方針
    - DFS
    - BFS
    - Union Find
    - 前回と同じ
- まずは実装しやすいDFSでやる
- 再帰の深さは最大でも250 -> 大丈夫
- 訪問済みの管理はgridと同じ大きさのvisitedを作って管理
- あとは実装

## Step1
- DFSで実装
- time: O(mn), space: O(mn)

## Step2
- BFSとUnion Findでも実装
    - `step2_bfs.py`
    - `step2_union_find.py`
- Union Findには、パス圧縮とUnion by Rankをともに入れた

## Step3
- 1回目: 4m30s
- 2回目: 3m35
- 3回目: 3m30
