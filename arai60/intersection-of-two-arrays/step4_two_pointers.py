class Solution:
    def intersection(self, nums1: List[int], nums2: List[int]) -> List[int]:
        nums1_sorted = sorted(nums1)
        nums2_sorted = sorted(nums2)

        index_nums1 = 0
        index_nums2 = 0
        intersection = []
        while index_nums1 < len(nums1_sorted) and index_nums2 < len(nums2_sorted):
            if nums1_sorted[index_nums1] < nums2_sorted[index_nums2]:
                index_nums1 += 1
                continue
            if nums1_sorted[index_nums1] > nums2_sorted[index_nums2]:
                index_nums2 += 1
                continue

            common = nums1_sorted[index_nums1]
            intersection.append(common)
            while index_nums1 < len(nums1_sorted) and nums1_sorted[index_nums1] == common:
                index_nums1 += 1
            while index_nums2 < len(nums2_sorted) and nums2_sorted[index_nums2] == common:
                index_nums2 += 1

        return intersection
