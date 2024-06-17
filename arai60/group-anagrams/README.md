## 考察
- 過去に解いたことあり
- 方針
    - anagram判定は以下の2つが考えられる
        - sortして比較
            - time: O(n log n), space: O(1)
        - countingして比較
            - time: O(n), space: O(26)
        - n: 各文字列の長さ
    - グループ化
        - HashMapを使う
        - キーとして、sortしたものかcountingしたものを使う
            - Pythonではハッシュ化するためにdictはイミュータブルにする必要あり
- まずはsortを使ってやってみる
- あとは実装

## Step1
- sortを使って実装した
- time: O(nm log m), space: O(nm)
- n: strs.length, m: max(strs[i].length)

## Step2
- countingでもやってみる
- frozensetを使ったけど、英小文字のみなので、26個の要素のlistを持ってtupleに変換してもいいかもしれない
- time: O(nm), space: O(nm)

## Step3
- 実装難易度は同じなので、より効率の良いstep2の手法で実装した
- 1文字変数を使っているところがあったので、省略しないように書き直した
- 1回目: 3m13s
- 2回目: 2m03s
- 3回目: 1m27s

## Step4
- Pythonはよしなにやってくれている文字列のコピーなどの部分をちゃんと考えたかったので、同じ処理をC++でも実装した
    - `step4_counting.cpp`
    - `step4_sorting.cpp`
