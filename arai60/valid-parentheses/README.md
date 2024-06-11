## 考察
- 過去に解いたことあり
- 方針
    - stackを使って対応を見ていく
        - 前から文字を見ていって、open bracketが来たらstackに積む
        - close bracketが来たら、stackから要素をpopして対応をチェックする(stackが空じゃないかだけ注意)
        - 最後にstackが空になっていたらOK
        - time: O(n), space: O(n)
- あとは実装

## Step1
- 上のアルゴリズムを実装
- time: O(n), space: O(n)

## Step2
- 手続き的にbracketの対応関係を判定していた箇所を、辞書を使って宣言的な記述に変更
    - 結果、余計なif文がかなり減った

## Step3
- 1回目: 1m51s
- 2回目: 1m53s
- 3回目: 1m28s

## Step4
- レビューを元にコードを修正
- 変数名の見直し
    - stack -> bracket_stack
        - 何を入れるstackなのかを明確に
    - bracket_pairs -> open_to_close
        - 例えば、open_to_close[open_bracket] という記述を見たときにclose_bracketが返ってくることが一目でわかる
        - より具体的になって、わかりやすくなった感覚
- `if not open_to_close[open_bracket] == c:` と書いていたところを `if open_to_close[open_bracket] != c:`に
- early continueしてネストを浅く
