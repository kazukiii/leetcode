class Solution:
    def isValid(self, s: str) -> bool:
        bracket_stack = []
        open_to_close = {
            '(': ')',
            '{': '}',
            '[': ']',
        }
        for c in s:
            if c in open_to_close:
                bracket_stack.append(c)
                continue

            if not bracket_stack:
                return False

            open_bracket = bracket_stack.pop()
            if open_to_close[open_bracket] != c:
                return False

        return not bracket_stack
