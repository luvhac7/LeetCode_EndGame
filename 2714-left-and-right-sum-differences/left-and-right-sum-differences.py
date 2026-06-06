class Solution:
    def leftRightDifference(self, a: List[int]) -> List[int]:
        return [abs(l - r) for l, r in zip([*accumulate(a, initial=0)][:-1], [*accumulate(a[::-1], initial=0)][-2::-1])]
