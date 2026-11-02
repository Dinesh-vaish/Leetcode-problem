from collections import defaultdict
from bisect import bisect_right

class Solution:
    def numMatchingSubseq(self, s: str, words: list[str]) -> int:

        pos = defaultdict(list)

        for i, ch in enumerate(s):
            pos[ch].append(i)

        ans = 0

        for word in words:
            prev = -1
            flag = True

            for ch in word:

                arr = pos[ch]

                idx = bisect_right(arr, prev)

                if idx == len(arr):
                    flag = False
                    break

                prev = arr[idx]

            if flag:
                ans += 1

        return ans