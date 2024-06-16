class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        n = len(nums)
        num_to_index = {}
        for i in range(n):
            complement = target - nums[i]
            if complement in num_to_index:
                return [i, num_to_index[complement]]
            num_to_index[nums[i]] = i

        raise Exception()
