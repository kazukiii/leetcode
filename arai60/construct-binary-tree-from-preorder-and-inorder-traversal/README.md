## 考察
- 過去に解いたことあり
- 方針
    - 基本的な考え方は、それぞれのtraversalをrootと左部分木と右部分木に分けること
        - まず、preorderの先頭がroot
        - inorderの中からrootを検索して、その左が左部分木、右が右部分木
            - 各部分木のサイズもわかる
            - `preorder and inorder consist of unique values.`
                - この制約がかなり重要
        - あとは再帰的に構築できる
        - 再帰の深さについては、最大で3000なため、C++なら問題ない
- あとは実装

## Step1
- std::findのドキュメントを見た
    - https://en.cppreference.com/w/cpp/algorithm/find
    - 計算量はO(n)
- time: O(n^2), space: O(n^2)

## Step2
- vectorのコピーが気になるので、indexを介してpreorder, inorderを使い回す書き方に変更した
    - time: O(n^2), space: O(n)
    - `stpe2.cpp`
- 他の人のPRを検索
    - https://github.com/fhiyo/leetcode/pull/31
        - 「preorderとinorderのstart」と「subtreeのsize」だけで十分 -> 引数は1つ減らせる
        - HashMapを使った高速化
        - preorderの順にノードを見ていき、木の根から順にノードの場所をinorderの位置を見ながら確定していく手法
            - このやり方も書いておきたい
            - `step2_preorder.cpp` へ追加
            - time: O(n^2), space: O(n)
    - https://github.com/YukiMichishita/LeetCode/pull/12
    - https://github.com/sakupan102/arai60-practice/pull/30
        - 「定数倍高速化」について
            - https://github.com/sakupan102/arai60-practice/pull/30#discussion_r1599277520
        - std::rotateは first, middle, lastという表記を使っている
            - https://github.com/sakupan102/arai60-practice/pull/30#discussion_r1599283671

## Step3
- 1回目: 11m30s
- 2回目: 9m13s
- 3回目: 8m48s
