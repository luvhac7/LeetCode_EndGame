class Solution:
    def minimumPushes(self, w: str) -> int:
        return sum(
            (i//8+1)*v for i,v in enumerate(sorted(Counter(w).values(),reverse=True))
        )