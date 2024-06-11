class Solution:
    def isValid(self, s: str) -> bool:
        stack = []
        for c in s:
            if c in ['(', '{', '[']:
                stack.append(c)
            else:
                if not stack:
                    return False

                open_bracket = stack.pop()
                if c == ')':
                    if not open_bracket == '(':
                        return False
                elif c == '}':
                    if not open_bracket == '{':
                        return False
                else:
                    if not open_bracket == '[':
                        return False

        return not stack
