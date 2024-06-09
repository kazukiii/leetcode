## 考察
- 初見の問題
- 昨日の Remove Duplicates from Sorted List の発展かな
- ぱっと見で次の2つの解法を考えた
    - 昨日の Remove Duplicates from Sorted List で考えたことを少し発展させて、スキップ回数が1以上になったらノードを削除すればよさそう
        - 現在のノードを削除したい場合が出てくるので、直前のノードも覚えておく必要
        - time: O(n), space: O(1)
    - std::mapで度数分布を求めておいて、1回しか出現しないノードを順番に繋いでいく
        - time: O(n log n), space: O(n)
    - どちらも制約的には問題なさそう
- 上の方法でやってみる
- あとは実装

## Step1
- 上で考えたアルゴリズムを実装
- 一番最初のノードを消したい場合もあるので、処理をシンプルにするため、ダミーヘッドを用意した
- 前回指摘されたメモリーリークに気をつけた
- time: O(n), space: O(1)

## Step2
- Solutionsをいくつか覗いてみた
- もっとコードをシンプルに出来そう(skip_countは使わなくてもよさそう)
- ロジックを整理
    - 現在のノードの値と次のノードの値が等しいことが確定した瞬間に重複があるのでその値のノードは削除することが確定する
    - その値のノードが続く限り、右に進んでいく。止まったところのnextノードが次に考えるべき値のノードになる
    - よってそこへcurrentを更新

## Step3
- 1回目: 1m59s(Step2のif文とwhile文の条件が被っていることが気になったので、少し書き直してみた)
- 2回目: 1m13s
- 3回目: 1m17s

## Step4
- 全てのレビューを元に出来る限りシンプルにしてみた
- 変更ポイント
    - 省略形を使わない
    - ダミーヘッドの初期化をコンストラクタを使用してシンプルに
    - ポインター1つだけで実装
        - これをやったことで、この問題の構造が前回の Remove Duplicates from Sorted List と同じ構造に見えた
    - early returnしてネストを出来る限り浅く保つ
    - 長い条件は変数化する
    - (スキップ判定については必要がなくなったので削除)