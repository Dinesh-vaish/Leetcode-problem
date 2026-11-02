class Solution:
    def uniqueMorseRepresentations(self, words: list[str]) -> int:

        morse = [
            ".-", "-...", "-.-.", "-..", ".", "..-.",
            "--.", "....", "..", ".---", "-.-", ".-..",
            "--", "-.", "---", ".--.", "--.-", ".-.",
            "...", "-", "..-", "...-", ".--", "-..-",
            "-.--", "--.."
        ]

        my_set = set()

        for word in words:

            ans = ""

            for ch in word:
                index = ord(ch) - ord('a')
                ans += morse[index]

            my_set.add(ans)

        return len(my_set)