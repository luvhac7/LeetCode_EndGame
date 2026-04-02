from collections import defaultdict

class Solution:
    def maxNumOfSubstrings(self, s: str) -> list[str]:
        # 1. Find the first and last occurrence of each character
        first = {c: i for i, c in enumerate(s[::-1])}
        first = {c: len(s) - 1 - i for c, i in first.items()}
        last = {c: i for i, c in enumerate(s)}
        
        # Helper to expand a range [i, j] to include all characters within it
        def get_valid_range(i):
            end = last[s[i]]
            j = i
            while j <= end:
                # If a character inside [i, end] starts before i, 
                # this starting point i is invalid for a greedy 'minimal' range.
                if first[s[j]] < i:
                    return -1
                end = max(end, last[s[j]])
                j += 1
            return end

        # 2. Collect all valid minimal intervals
        intervals = []
        for char in set(s):
            start = first[char]
            end = get_valid_range(start)
            if end != -1:
                intervals.append((start, end))
        
        # 3. Greedy selection: Sort by end time to get the maximum non-overlapping intervals
        intervals.sort(key=lambda x: x[1])
        
        ans = []
        last_end = -1
        for start, end in intervals:
            if start > last_end:
                ans.append(s[start:end+1])
                last_end = end
                
        return ans
