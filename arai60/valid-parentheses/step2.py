class Solution:
    def isValid(self, s: str) -> bool:
        stack = []
        bracket_pairs = {
            '(': ')',
            '{': '}',
            '[': ']',
        }
        for c in s:
            if c in bracket_pairs:
                stack.append(c)
            else:
                if not stack:
                    return False

                open_bracket = stack.pop()
                if not bracket_pairs[open_bracket] == c:
                    return False

        return not stack
