class Solution:
    def minWindow(self, s: str, t: str) -> str:
        if len(t) > len(s):
            return ""

        freq = {}

        # Count characters of t
        for ch in t:
            freq[ch] = freq.get(ch, 0) + 1

        left = 0
        count = len(t)

        min_len = float("inf")
        start = 0

        for right in range(len(s)):

            if s[right] in freq and freq[s[right]] > 0:
                count -= 1

            freq[s[right]] = freq.get(s[right], 0) - 1

            while count == 0:

                if right - left + 1 < min_len:
                    min_len = right - left + 1
                    start = left

                freq[s[left]] = freq.get(s[left], 0) + 1

                if freq[s[left]] > 0:
                    count += 1

                left += 1

        if min_len == float("inf"):
            return ""

        return s[start:start + min_len]