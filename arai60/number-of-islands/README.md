## 考察
- 何回か解いたことあり
- つまり、抽象化すると陸をノードとするグラフの連結成分の数を求めればOK
- 方針
    - DFS
    - BFS
    - Union Find
        - 昔この問題をUnion Findでやってみたことがあるが、あまり綺麗に書けなかった記憶
        - 常識の範囲内に入っているか気になる
- まずは一番実装しやすいDFSでやる
- あとは実装

## Step1
- DFSで実装した
- time: O(mn), space: O(mn)
- 気になった点
    - 関数内に関数を書く書き方をよく使っているけど、これ大丈夫？
        - 実務ではこの書き方使ったことない

## Step2
- 他の人のPRを検索
- dfsという名前は使わないように
    - よくない癖が付いてた。。
    - Ref. https://discord.com/channels/1084280443945353267/1231966485610758196/1236231890038689844
- 元のgridを破壊的に変更して陸を沈めていく方法もあるのか
    - メモリは抑えられるが、バグりそう
    - Ref. https://github.com/hayashi-ay/leetcode/pull/33/files#r1648958531
- LANDとWATERはenum的に定義しておくと可読性良さそう
    - Pythonのenumはパフォーマンスが悪いみたいなのをどっかで見た気がする
        - でもまあそれがボトルネックになることは考えられない
    - ここでは定数として定義しておくのが良さそう
    - Ref. https://github.com/hayashi-ay/leetcode/pull/33/files#diff-225d97de8f43ab6e115258cc7d483e5a343d8556774b2dde47c392b38b49e89bR37
- 関数内に関数を書くのはとくにコメント付いてないので大丈夫そう
- Union Find実装もある
    - Ref. https://github.com/hayashi-ay/leetcode/pull/33/files#diff-225d97de8f43ab6e115258cc7d483e5a343d8556774b2dde47c392b38b49e89bR98
- あとはBFSでもやってみる
    - `step2.py` へ追加

## Step3
- 1回目: 5m37s
- 2回目: 5m12s
- 3回目: 4m51s

## Step4
- レビューを元に修正
- 変数名の見直し
    - n_row -> num_rows
    - n_col -> num_cols
    - drow -> delta_row
    - dcol -> delta_col
- explore_islandの引数にtupleを渡すのではなく、intを2つ渡すようにした
- 方向を行と列で分けて書いていたけど、ペアにしてみた
