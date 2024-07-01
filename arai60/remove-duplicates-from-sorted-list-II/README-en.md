## Considerations
- First-time problem
- Seems to be an extension of yesterday's "Remove Duplicates from Sorted List"
- Initially thought of two solutions:
    - Extend the idea from yesterday's "Remove Duplicates from Sorted List" and delete the node if the skip count becomes 1 or more
        - Need to remember the previous node because there will be cases where the current node needs to be deleted
        - time: O(n), space: O(1)
    - Use std::map to find the frequency distribution and connect nodes that appear only once in order
        - time: O(n log n), space: O(n)
    - Both solutions seem fine within the constraints
- I'll try the above methods
- Now to implement

## Step 1
- Implemented the algorithm considered above
- Prepared a dummy head to simplify processing since the first node might need to be deleted
- Took care to avoid the memory leak pointed out last time
- time: O(n), space: O(1)

## Step 2
- Checked a few solutions
- Realized I could simplify the code (skip_count might not be needed)
- Streamlined the logic:
    - The moment it's confirmed that the current node's value equals the next node's value, the node with that value is confirmed for deletion
    - Move right as long as nodes with that value continue. The next node after stopping will be the node with the next value to consider
    - Therefore, update current to that node

## Step 3
- First time: 1m59s (Rewrote slightly as the if and while conditions in Step 2 overlapped)
- Second time: 1m13s
- Third time: 1m17s

## Step 4
- Simplified the code as much as possible based on all reviews
- Points of change:
    - Avoid using abbreviations
    - Simplify dummy head initialization using the constructor
    - Implement using only one pointer
        - Doing this made the structure of this problem look the same as the previous "Remove Duplicates from Sorted List"
    - Use early return to keep nesting as shallow as possible
    - Convert long conditions into variables
    - (Removed skip check as it was no longer needed)
