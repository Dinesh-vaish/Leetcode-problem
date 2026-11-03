class Solution:
    def restoreIpAddresses(self, s: str) -> list[str]:

        ans = []

        def dfs(i, path):

            if len(path) == 4:
                if i == len(s):
                    ans.append(".".join(path))
                return

            for length in range(1, 4):

                if i + length > len(s):
                    break

                part = s[i:i+length]

                # Leading zero check
                if len(part) > 1 and part[0] == "0":
                    continue

                # Range check
                if int(part) > 255:
                    continue

                dfs(i + length, path + [part])

        dfs(0, [])

        return ans