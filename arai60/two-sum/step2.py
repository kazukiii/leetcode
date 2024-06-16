class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        n = len(nums)
        nums_with_index = [(nums[i], i) for i in range(n)]
        nums_with_index.sort()

        left = 0
        right = n - 1
        while left < right:
            num_left, index_left = nums_with_index[left]
            num_right, index_right = nums_with_index[right]
            sum_ = num_left + num_right
            if sum_ == target:
                return [index_left, index_right]
            if sum_ < target:
                left += 1
            else:
                right -= 1

        raise Exception()
