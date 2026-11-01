class Solution:
    def mostCommonWord(self, paragraph: str, banned: list[str]) -> str:
        p = paragraph.lower()

        for ch in "!?',;.":
            p = p.replace(ch, " ")

        words = p.split()

        my_dist = {}

        for word in words:
            if word not in banned:
                my_dist[word] = my_dist.get(word, 0) + 1
        return max(my_dist, key=my_dist.get)