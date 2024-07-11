## 考察
- 過去に解いたことあり
- 方針
    - DFS/BFS
        - 根から葉に向かって和を追跡していけばOK
        - 条件を満たす葉を見つけた場合はその時点でreturnしたい
        - BFSでやるメリットはあまりなさそう
        - 再帰の深さは最大5000なので、Pythonのデフォルトだとスタックオーバーフローしてしまう
- まずは非再帰DFSで実装してみる

## Step1
- 非再帰DFSで実装
- current_sumのcurrentは付けなくてもいいかもしれないが、sumが予約語なのでcurrent_sumとした
- 一応、スタック->キューにすればBFSにもなる
- time: O(n), space: O(n)

## Step2
- 再帰DFSでも実装
- 他の人のPRを検索
    - https://github.com/SuperHotDogCat/coding-interview/pull/37
        - targetSumから引いていく実装をしている
        - helperがいらなくなるメリットがありそう
    - https://github.com/fhiyo/leetcode/pull/27
        - こちらもStep1時点でtargetSumから引いていく実装
        - 再帰で書ける場合はそちらが書きやすいことが多い
            - -> そうだと思った。自分もスタックオーバーフローの危険性を説明した上で、まずは再帰で実装する動きを取ろうと思う。
    - https://github.com/sakupan102/arai60-practice/pull/26
        - 足していく実装
        - 再帰で書く時、`return find_target_path_sum(node.left, path_sum) or find_target_path_sum(node.right, path_sum)` と書いても、left childからtrueが返ってくれば、短絡評価によってright childは呼び出されないのか -> 自分のコードは冗長な書き方をしていたので修正する必要

## Step3
- 1回目: 1m11s
- 2回目: 1m09s
- 3回目: 1m03s
