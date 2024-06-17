class Solution:
    def groupAnagrams(self, strs: List[str]) -> List[List[str]]:
        sorted_str_to_anagrams = defaultdict(list)
        for s in strs:
            sorted_str = str(sorted(s))
            sorted_str_to_anagrams[sorted_str].append(s)

        return list(sorted_str_to_anagrams.values())
