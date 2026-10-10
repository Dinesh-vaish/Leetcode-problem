
class Solution:
    def eventualSafeNodes(self, graph: list[list[int]]) -> list[int]:
        safe = set()

        def dfs(node):
            if node in safe:
                return True

            if node in path:
                return False

            path.add(node)

            for neighbor in graph[node]:
                if not dfs(neighbor):
                    path.remove(node)
                    return False

            path.remove(node)
            safe.add(node)
            return True

        ans = []

        for node in range(len(graph)):
            path = set()
            if dfs(node):
                ans.append(node)

        return ans
