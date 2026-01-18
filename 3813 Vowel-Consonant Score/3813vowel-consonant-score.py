class Solution:
    def vowelConsonantScore(self, s: str) -> int:
        c = 0
        v = 0
        result = 0

        for letter in s:
            if letter in "abcdefghijklmnopqrstuvwxyz":
                if letter in "aeiou":
                    v += 1
                else:
                    c += 1

        if c > 0:
            result = v // c

        return result
