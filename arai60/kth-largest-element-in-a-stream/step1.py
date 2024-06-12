class KthLargest:
    def __init__(self, k: int, nums: List[int]):
        self.k = k
        self.num_min_heap = []
        for num in nums:
            heapq.heappush(self.num_min_heap, num)
            if len(self.num_min_heap) > self.k:
                heapq.heappop(self.num_min_heap)

    def add(self, val: int) -> int:
        heapq.heappush(self.num_min_heap, val)
        if len(self.num_min_heap) > self.k:
            heapq.heappop(self.num_min_heap)
        return self.num_min_heap[0]



# Your KthLargest object will be instantiated and called as such:
# obj = KthLargest(k, nums)
# param_1 = obj.add(val)
