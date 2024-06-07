## Considerations
- I've solved this before.
- At first glance, two methods come to mind:
    - Using a HashSet:
        - Keep track of nodes that have already been seen.
        - Time: O(n), Space: O(n)
    - Using two pointers:
        - An extension of the Linked List cycle detection.
        - It’s probably impossible to come up with this on the spot if you haven’t done it before.
        - Time: O(n), Space: O(1)
- The list traversal methods that come to mind are iterative and recursive.
    - Considering the overhead of recursive calls, I can’t think of any benefits to making it recursive.
    - I’ll go with the iterative method.
- Next, implementation.

## Step 1
- Implemented using the set method.
- There were no particular issues.
- Time: O(n), Space: O(n)

## Step 2
- Improved space complexity using two pointers.
- Since I had used this approach before, there were no particular issues.
- It seems impossible to think of this on the spot without prior knowledge.
- Time: O(n), Space: O(1)

## Step 3
- First attempt: 1m12s
- Second attempt: 1m01s
- Third attempt: 57s

## Step 4
- Revised the code based on the review.
- Removed unnecessary blank lines.
    - PEP8
    - "Use blank lines in functions, sparingly, to indicate logical sections."
    - https://peps.python.org/pep-0008/#blank-lines
