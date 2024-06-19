## 考察
- 過去に解いたことあり(覚えていない)
- 方針
    - ソートして見ていく
        - ソートすることにより同じ文字は隣合う
        - 元のインデックスを保持しておく必要あり
        - time: O(n lon n), space: O(n log n) -> time, spaceともにソートの分
    - 度数分布を取得してループ
        - これも元のインデックスを保持する必要ありそう
            - もしかしたらC++のunordered_mapは挿入順を保持する？
                - わからないのでドキュメント確認する必要
                - さくっと調べたが特にそのような記載は見当たらなかった
                    - https://en.cppreference.com/w/cpp/container/unordered_map
        - time: O(n), space: O(n)
- 下の方針で行く
- あとは実装

## Step1
- 上で考えたアルゴリズムを実装
- time: O(n), space: O(n)

## Step2
- 他の人のPRを検索
- Javaには順序のあるHashMapがあるらしい、平衡木を使う方法もある
    - Ref. https://github.com/Ryotaro25/leetcode_first60/pull/16/files#r1642839594

- Pythonのdictは挿入順序を保持するみたい
    - Ref. https://github.com/nittoco/leetcode/pull/20/files#diff-c6374213bbbe17c2850ccd0bfb422c1f5bf40576b93320647cbfd9e9e3724c74R48

- 文字列を2回走査すれば、インデックスを保持する必要はなかった
    - これは思いつかなかった
    - 時間的にも十分だし、一番シンプル
    - https://github.com/nittoco/leetcode/pull/20/files#diff-c6374213bbbe17c2850ccd0bfb422c1f5bf40576b93320647cbfd9e9e3724c74R119

- 上記を考慮して、C++なら文字列を2回走査するのが一番シンプルだと思ったので修正

## Step3
- 1回目: 55s
- 2回目: 50s
- 3回目: 50s
