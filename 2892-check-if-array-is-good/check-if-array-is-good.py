class Solution:
    def isGood(self, a: List[int]) -> bool:
        a.sort()
        return a== [*range(1, n := len(a)),n - 1]