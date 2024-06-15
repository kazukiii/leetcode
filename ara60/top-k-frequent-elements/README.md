## 考察
- 過去に解いたことあり
- 方針
    - まずはカウントを行う
        - time: O(n), space: O(n)
    - カウントした結果を元にtopkを算出
        - 方針は3つ程思い浮かぶ
        - ソート
            - nums.length <= 10^5 なので、計数ソートが良さそう
            - time: O(n), space: O(n)
        - クイックセレクト
            - ランダムにpivotを決める
            - pivotの左側にpivot以下のもの、右側にpivotより大きいものを集める
            - pivotが何番目かが確定するので、どちら側にk番目があるかは明白
            - これを繰り返せばいい
            - any orderなので、pivotがk番目に来たら、pivotとその左側を返せばいい
            - time: O(n), space: O(1)
        - ヒープを使う
            - サイズkの最小ヒープを用意して、サイズを保つように入れていく
            - time: O(n log k), space: O(k)
- 全部さくっと実装できるようにしておきたい
- まずはソートでやる
- あとは実装

## Step1
- 計数ソートを実装した
- time: O(n), space: O(n)

## Step2
- ヒープとクイックセレクトでも実装してみた
- 3通り実装してみて、計数ソートとクイックセレクトは脳の負荷が高い
- ヒープ使ってやるのが一番良さそう
- あとC++、エラー内容がPythonよりわかりにくく感じた(これは慣れかもしれない)

## Step3
- 1回目: 3m02s
- 2回目: 2m45s
- 3回目: 2m30s

## Step4
- レビューを元に修正
- 変数名の見直し
    - num_count -> num_to_count
    - min_heap -> min_count_and_nums
    - key, value -> num, count
- 拡張for文のコロンの前後にはspaceを入れる
- pairの代わりにstructを使うように修正

