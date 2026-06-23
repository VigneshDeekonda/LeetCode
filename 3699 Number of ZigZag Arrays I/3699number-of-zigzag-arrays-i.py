class Solution:
    def zigZagArrays(self, n: int, l: int, r: int) -> int:
        MOD = 10**9 + 7

        m = r - l + 1

        # up[i] = count of sequences ending at value i
        # where next move must be UP
        # down[i] = count of sequences ending at value i
        # where next move must be DOWN

        up = [1] * m
        down = [1] * m

        for _ in range(n - 1):
            new_up = [0] * m
            new_down = [0] * m

            # prefix sums of up
            pref = [0] * (m + 1)
            for i in range(m):
                pref[i + 1] = (pref[i] + up[i]) % MOD

            # suffix sums of down
            suff = [0] * (m + 1)
            for i in range(m - 1, -1, -1):
                suff[i] = (suff[i + 1] + down[i]) % MOD

            for i in range(m):
                # previous value smaller => move up
                new_down[i] = pref[i]

                # previous value larger => move down
                new_up[i] = suff[i + 1]

            up, down = new_up, new_down

        return (sum(up) + sum(down)) % MOD
        