MOD = int(1e9+7)
pwr = [*accumulate(range(100000), lambda a,e: (a*10)%MOD, initial=1)]
class Solution:
    def sumAndMultiply(self, s: str, queries: List[List[int]]) -> List[int]:
        prl = [*accumulate(s, lambda a,e: a + (e!='0'), initial=0)]
        prs = [*accumulate(map(int,s), initial=0)]
        prx = [*accumulate(map(int,s), lambda a,e: a if not e else (a*10+e)%MOD, initial=0)]
        return [((prx[r+1] - (prx[l] * pwr[prl[r+1]-prl[l]])%MOD) * (prs[r+1] -prs[l])) %MOD  for l,r in queries]
        