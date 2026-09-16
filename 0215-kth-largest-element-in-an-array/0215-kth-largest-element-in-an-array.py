class Solution:
    def findKthLargest(self, nums: list[int], k: int) -> int:
        minh = []
        for i in nums:
            heapq.heappush(minh, i)
            if len(minh) > k:
                heapq.heappop(minh)
        return minh[0]
