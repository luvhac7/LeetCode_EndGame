class Solution:
    def rotateString(self, s: str, g: str) -> bool:
        return len(s)==len(g)and(s+s).find(g)!=-1
        