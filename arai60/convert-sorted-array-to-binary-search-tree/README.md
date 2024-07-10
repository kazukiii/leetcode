## 考察
- 初見の問題
- 方針
    - 真ん中がroot、その左側がleft subtree、右側がright subtreeとなるので十分
        - あとは再帰的に構築できる
        - height-balancedなので、木の高さはlogオーダー
        - よって再帰処理で書いてOK
        - time: O(n), space: O(n)
    - dummyの値を持ったcomplete binary treeを構築して、inorder traversalしながら値をセットしても良さそう
        - BSTをinorder traversalすると、昇順ソートになるため
        - 1ステップ挟むため少しコードが長くなりそう
        - time: O(n), space: O(n)
- まずは最初の方針を実装して、Step2でもう一方のアイデアをやってみる

## Step1
- 上で考えたアルゴリズムを実装
- time: O(n), space: O(n)

## Step2
- 上で考えたもう一方のアルゴリズムも実装
- 他の人のPRを検索
    - https://github.com/fhiyo/leetcode/pull/26
        - 方針はだいたい良さそう
        - 半開区間でやっている
        - これは二分探索というのかな？
            - https://github.com/fhiyo/leetcode/pull/26#discussion_r1651955390
            - たしかに見る区間を半々にはしているが
        - midという形容詞について
            - https://github.com/fhiyo/leetcode/pull/26#discussion_r1654034973
        - Boxについて
            - https://github.com/fhiyo/leetcode/pull/26#discussion_r1652886883
            - 初めて見た
            - 参照をラップしている？一般的な概念なのかな？後ほど詳しく調べる
    - https://github.com/Mike0121/LeetCode/pull/13
        - 方針はだいたい良さそう
        - 閉区間、半開区間ともに書いている

## Step3
- 1回目: 2m30s
- 2回目: 1m40s
- 3回目: 1m37s
