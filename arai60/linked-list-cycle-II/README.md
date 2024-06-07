## 考察
- 昔解いたことがある
- ぱっと見で次の2つの手法が思い浮かぶ
    - HashSetを使う
        - すでに見たことがあるノードを覚えておく
        - time: O(n), space: O(n)
    - 2 pointersを使う
        - Linked Listのサイクル検出の発展
        - 一回やったことがないと、その場で思いつくのはおそらく無理
        - time: O(n), space: O(1)
- リストの走査方法はiterativeな方法とrecursiveな方法が思い浮かぶ
    - 再帰呼び出しによるオーバーヘッドなどを考えると再帰処理にするメリットは思い浮かばない
    - iterativeな方法でいく
- あとは実装

## Step1
- setを使った方法で実装してみた
- とくに詰まるところはなかった
- time: O(n), space: O(n)

## Step2
- 2 pointersを使って、空間計算量を改善
- 過去に同じ思考を踏んだことがあったため、とくに詰まるところはなかった
- 知っていないと、その場で思いつくのは無理な気がする
- time: O(n), space: O(1)

## Step3
- 1回目: 1m12s
- 2回目: 1m01s
- 3回目: 57s

## Step4
- レビューを元にコードを修正
- 不要だと思う改行を削除
    - PEP8
    - `Use blank lines in functions, sparingly, to indicate logical sections.`
    - https://peps.python.org/pep-0008/#blank-lines
