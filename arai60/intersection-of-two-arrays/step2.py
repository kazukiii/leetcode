class Solution:
    def intersection(self, nums1: List[int], nums2: List[int]) -> List[int]:
        nums1.sort()
        nums2.sort()

        index_nums1 = 0
        index_nums2 = 0
        answer = []
        while index_nums1 < len(nums1) and index_nums2 < len(nums2):
            if nums1[index_nums1] < nums2[index_nums2]:
                index_nums1 += 1
                continue
            if nums1[index_nums1] > nums2[index_nums2]:
                index_nums2 += 1
                continue

            common = nums1[index_nums1]
            answer.append(common)
            while index_nums1 < len(nums1) and nums1[index_nums1] == common:
                index_nums1 += 1
            while index_nums2 < len(nums2) and nums2[index_nums2] == common:
                index_nums2 += 1

        return answer
