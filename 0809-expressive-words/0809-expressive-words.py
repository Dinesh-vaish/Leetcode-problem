class Solution:
    def expressiveWords(self, s: str, words: list[str]) -> int:

        def check(word):

            i = 0
            j = 0

            while i < len(s) and j < len(word):

                if s[i] != word[j]:
                    return False

                count1 = 0
                count2 = 0

                ch = s[i]

                while i < len(s) and s[i] == ch:
                    count1 += 1
                    i += 1

                while j < len(word) and word[j] == ch:
                    count2 += 1
                    j += 1

                if count1 < count2:
                    return False

                if count1 != count2 and count1 < 3:
                    return False

            return i == len(s) and j == len(word)

        ans = 0

        for word in words:
            if check(word):
                ans += 1

        return ans