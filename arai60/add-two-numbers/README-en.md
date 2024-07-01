## Considerations
- Solved this problem in the past
- Approach
    - Keep track of carry while adding corresponding nodes one by one (similar to manual addition in your head)
        - time: O(n), space: O(n)
    - Pay special attention if a carry remains at the end
- Traversing the list can be done iteratively or recursively
    - Can't think of any benefits for recursion, so will go with iteration
- Now to implement

## Step 1
- Implemented the algorithm considered above
- One concern is memory management
    - Allocating new nodes on the stack won't work as memory is released when out of scope
    - Created objects in the heap, but unsure who is responsible for managing these objects
    - Haven't used C++ in a professional setting, but how is this handled in practice?
        - Would using smart pointers for Linked List pointers help? -> Memory should be automatically released when references are gone

## Step 2
- Searched other people's PRs regarding memory management
    - There might be limitations specific to LeetCode, but it's important to be aware of this issue
    - Ref. https://github.com/Ryotaro25/leetcode_first60/pull/5#discussion_r1611301775
- Fixed by incorporating the final carry check into the main logic

## Step 3
- First time: 2m00s
- Second time: 1m58s
- Third time: 1m33s
