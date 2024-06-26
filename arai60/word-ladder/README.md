## 考察
- 過去に解いたことあり
- グラフを構築して、各エッジの重みが1の単一始点最短経路問題に落とし込む
    - BFS
        - time: O(mn), space: O(mn)
        - m: wordList.length, n: beginWord.length
        - 一番速い
    - Dijkstra
        - time: O(mn log m), space: O(mn)
        - 十分間に合う
- まずはBFSで実装

## Step1
- BFSで実装
- time: O(mn), space: O(mn)

## Step2
- 練習のため、Dijkstraでも実装
    - `step2_dijkstra.cpp`
    - 可読性を上げるためには、pairを使っているところはstructを定義した方が良さそう(一旦実装のしやすさを優先した)
- 他の人のPRを検索
    - 先に隣接リストを作る方法もあるが構築に時間がかかる
        - C++なら通る？
        - https://github.com/fhiyo/leetcode/pull/22/files#r1641740089
    - 編集距離を計算する方法
        - https://discord.com/channels/1084280443945353267/1183683738635346001/1199046289686548581
        - ハミング距離、初めて聞いた
            - 編集距離の一種
            - https://github.com/fhiyo/leetcode/pull/22/files#diff-31faf98ca7f81fdbb8e7511dfb545105b62656d6f2da427b91510f79117ee192R51
    - 一文字*に置き換えて辞書で保存する方法
        - https://discord.com/channels/1084280443945353267/1183683738635346001/1199046289686548581
- 気付いた点
    - next_word == endWordになった時点でearly returnした方が良さそう
    - next_wordが元のwordになる場合もあるので、弾ける
    - 引数がcamel caseなのが気になる場合は引数を書き換えればOK

## Step3
- 1回目: 6m34
- 2回目: 5m53s
- 3回目: 5m52s
