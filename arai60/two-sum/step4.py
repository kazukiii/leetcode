class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        num_to_index = {}
        for i, num in enumerate(nums):
            complement_value = target - num
            if complement_value in num_to_index:
                return [i, num_to_index[complement_value]]
            num_to_index[num] = i

        raise Exception('unreachable')
