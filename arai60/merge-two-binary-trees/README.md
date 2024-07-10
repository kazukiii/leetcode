## 考察
- 初見の問題
- 方針
    - DFS/BFS
        - 全ノードを探索しながら新しい二分木を生成して返すのが思い付く
        - どちらかの二分木を再利用もできそうだが、新しい二分木を作る方を選択
        - Pythonで関数からの戻り値をいじったら、他のところが壊れましたはびっくりしそう
- 再帰の最大深さが2000だが、まずは再帰で書いてみる
- Step2で非再帰に書き直そうと思う
- あとは実装

## Step1
- 再帰DFSで実装
- time: O(n), space: O(n)

## Step2
- 非再帰に書き換え
    - 3点を書き換えた
        - popの位置に再帰関数の処理を持ってくる
        - 再帰呼び出しをstackへのappendに変更
        - returnをcontinueへ変更
    - stack -> queueとすればBFSにもなる
- 他の人のPRを検索
    - めちゃくちゃシンプル
        - https://github.com/SuperHotDogCat/coding-interview/pull/35/files#diff-e23bfd258f7b29f3e94954b1beeca569cce5d7f3b17de6f3223729c1ebf588a5
        - 帰りがけで下から構築していくのは思い付かなかった...
        - これならhelperも作る必要ない
    - こちらもめちゃくちゃシンプル
        - https://github.com/fhiyo/leetcode/pull/25
        - 行きがけで書くにしてももう少し条件を整理できそう
- 帰りがけDFSで実装してみる

## Step3
- 1回目: 1m36s
- 2回目: 1m15s
- 3回目: 1m17s
