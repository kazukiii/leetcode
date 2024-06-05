## 考察
- 昔解いたことがある
- 2つの速さの異なるポインタを用意する(頭の中ではうさぎとかめを連想)
    - slow pointer: 1ステップで1つ進む
    - fast pointer: 1ステップで2つ進む
    - とすると、fastが終端にたどり着いてしまった場合はサイクルは存在しない
    - それ以外のケースでは、どこかでfastがslowに追いつく
- エッジケース
    - リストが空の場合はfalse
    - リストの要素が1つの場合もfalse
- あとは実装

## Step 1
- fast.nextがNoneになる場合、fast.next.nextが読めないのでそこだけ注意した
- time: O(n), space: O(1)

## Step 2
- fast, slowの初期化をタプルのアンパックを使って簡潔に表現
- while文の条件を見直してみた
    - 停止条件をfastまたはfast.nextがNoneになった場合に変更
    - fast.nextがNoneになった時点で、サイクルは存在しないことになるため

## Step 3
- 1回目: 47s
- 2回目: 46s
- 3回目: 45s
