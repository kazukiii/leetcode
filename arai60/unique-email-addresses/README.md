## 考察
- 初見の問題
- 方針
    - 文字列操作してHashSetに追加すればよさそう
        - C++にはたしかsplitがなかったはずなので、Pythonでやる
        - 文字列操作の代わりに正規表現でも出来そう
            - ソラでは書ける自信がない(書けるようになっておいた方がいい？)
            - 後ほど、調べながらやる
        - time: O(nm), space: O(nm)
        - n: emails.length, m: max_i(emails[i].length)
- あとは実装

## Step1
- splitとreplaceを使った
- time: O(nm), space: O(nm)

## Step2
- まずは正規表現でもやってみる -> `step2_re.py`
- 他の人のPRを検索
    - splitしてからreplaceした方が効率が良い
        - Ref. https://github.com/Mike0121/LeetCode/pull/31#discussion_r1642845600
    - 各emailに対する処理は関数化した方がわかりやすいかも
        - Ref. https://github.com/SuperHotDogCat/coding-interview/pull/30/files#r1641769186
    - 正規表現について
        - Ref. https://github.com/fhiyo/leetcode/pull/17#discussion_r1629618002

- 上記を元に各操作を関数化して組み合わせる書き方に修正した
- local_nameとdomain_nameの組み合わせをtupleで表現した

## Step3
- 1回目: 2m19s
- 2回目: 2m15s
- 3回目: 2m02s
