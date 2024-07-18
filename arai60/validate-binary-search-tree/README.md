## 考察
- 過去に解いたことあり
- 方針
    - 各ノードについて値の取り得る範囲を追跡すれば良い
    - time: O(n), space: O(n)
    - DFSでもBFSでもOK
- 再帰の深さについて
    - C++で考えるのは初めてなのでしっかり見積もってみる
    - スタックメモリのサイズについてはLinuxではデフォルトで8MBとして良さそう
        - 手元のmacで確認したところ同様に8MB
    - 各スタックフレームのサイズ
        - 引数
            - TreeNode* root: 8 bytes (以下、64bitシステムとして考える)
            - long long lower: 8 bytes
            - long long upper: 8 bytes
        - ローカル変数
            - なし
        - その他
            - 戻りアドレス: 8 bytes
            - ベースポインタ: 8 bytes
        - 合計: 40 bytes
    - 最大で 8000000 / 40 = 2 * 10^5 くらいは大丈夫そう
    - 今回はノード数が最大で10^4なので、見積もり上は再帰で書いても大丈夫
- Step1では、再帰DFSで実装する

## Step1
- 再帰DFSで実装
- time: O(n), space: O(n)

## Step2
- 非再帰でも実装 -> `step2.cpp`
- 他の人のPRを検索
    - https://github.com/fhiyo/leetcode/pull/30
        - inorder traversal したときにノードの値が昇順に整列されていればいいとして解いている
        - 再帰でyieldする解法は中々思いつかないので訓練したい
            - この発想はなかった
        - n-ary treeについても見ておく
            - https://github.com/fhiyo/leetcode/pull/30#discussion_r1659876811
    - https://github.com/sakupan102/arai60-practice/pull/29
        - Noneで初期化しておいて、最初のノードは比較せずに代入する方法もあります。Optional[int]です。
            - C++の書き方が参考になる
                - Pythonのように関数内に関数を定義する書き方
                - https://github.com/sakupan102/arai60-practice/pull/29#discussion_r1597676869
                - 練習しておく -> `step2_function.cpp`
    - https://github.com/Mike0121/LeetCode/pull/8
        - Inorderによる解法
            - 初見なら自分もこの方法をやるかもしれない

## Step3
- 1回目: 2m03s
- 2回目: 1m55s
- 3回目: 1m50s
