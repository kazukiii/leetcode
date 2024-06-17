class Solution:
    def groupAnagrams(self, strs: List[str]) -> List[List[str]]:
        counting_to_anagrams = defaultdict(list)
        for s in strs:
            char_to_count = defaultdict(int)
            for c in s:
                char_to_count[c] += 1
            counting_to_anagrams[frozenset(char_to_count.items())].append(s)

        return list(counting_to_anagrams.values())
