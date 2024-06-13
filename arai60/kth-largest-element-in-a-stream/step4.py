class KthLargest:
    def __init__(self, k: int, nums: List[int]):
        self.k = k
        self.num_min_heap = []
        for num in nums:
            self.add(num)

    def add(self, val: int) -> int:
        if len(self.num_min_heap) < self.k:
            heapq.heappush(self.num_min_heap, val)
        else:
            heapq.heappushpop(self.num_min_heap, val)
        return self.num_min_heap[0]



# Your KthLargest object will be instantiated and called as such:
# obj = KthLargest(k, nums)
# param_1 = obj.add(val)
