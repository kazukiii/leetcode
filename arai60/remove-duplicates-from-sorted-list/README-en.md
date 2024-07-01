## Considerations
- First-time problem
- Since it is sorted, nodes with the same value will be adjacent
- Keep track of the previous value, and if the current value is the same as the previous one, skip it
- If a new list is created for the return, the space complexity will be O(n), so ideally, pointers should be reconnected to achieve O(1) space complexity
- (A meta thought, but creating a new list would make the fact that the problem is about a Linked List meaningless)
- Skipping = connecting to the next next node should suffice
- Traversing the list can be done recursively, but as before, we'll go with iterative processing
- Now to implement it

## Step 1
- Implemented the above algorithm
- Made a wrong assumption by setting the dummy head as `ListNode* dummy = new ListNode();`
- Since `-100 <= Node.val <= 100`, I needed to use a value outside this range
- time: O(n), space: O(1)

## Step 2
- Realized that a dummy head wasn't necessary, so removed the extra processing

## Step 3
- First time: 1m03s
- Second time: 50s
- Third time: 53s

## Step 4
- Fixed the memory leak in the code from step 1
    - Basically, ensure memory allocation is done in the stack area
    - Ref. https://github.com/Ryotaro25/leetcode_first60/pull/8#discussion_r1615892524
    - Ref. https://github.com/Ryotaro25/leetcode_first60/pull/5#discussion_r1611245294
