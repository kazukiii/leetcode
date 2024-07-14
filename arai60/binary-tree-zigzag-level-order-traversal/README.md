## 考察
- 初見の問題
- 方針
    - BFS
        - レベルごとに探索して、levelを0始まりで考えたときに奇数なら逆順にして答えに追加すれば良さそう
        - 各reverse処理の計算量は要素数オーダーかかるが、全体としてはノード数で抑えられるので、amortized O(1)
        - time: O(n), space: O(n)
    - DFS
        - DFSでも出来るが、前回同様DFSで解くメリットは特にない
        - DFSは前回書いたので今回はスキップ
- BFSで、vectorを2つ用意する形で実装する

## Step1
- 他の人のPRを検索
    - https://github.com/fhiyo/leetcode/pull/29
        - 文字通りzigzagにtraverseしている
            - おそらくこれが想定解
            - どうやって考えたら思い付けるか落とし込むことが出来なかったので、一旦覚える
        - from_leftを用意している
            - levelの偶奇で判定するより可読性が高そう
    - https://github.com/YukiMichishita/LeetCode/pull/11
        - reverseしなくてもdequeを使えば、逆順になる
    - https://github.com/sakupan102/arai60-practice/pull/28
- `step2_zigzag_traverse.cpp` と `spte2_deque.cpp` を追加

## Step3
- 1回目: 3m52s
- 2回目: 3m20s
- 3回目: 3m25s
