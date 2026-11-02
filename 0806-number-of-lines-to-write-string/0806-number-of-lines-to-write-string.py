class Solution:
    def numberOfLines(self, widths: list[int], s: str) -> list[int]:

        lines = 1
        total = 0

        for ch in s:

            width = widths[ord(ch) - ord('a')]

            if total + width > 100:
                lines += 1
                total = width
            else:
                total += width

        return [lines, total]