class Solution:
    def groupAnagrams(self, strs: List[str]) -> List[List[str]]:
        counting_to_anagrams = defaultdict(list)
        for string in strs:
            character_to_count = defaultdict(int)
            for character in string:
                character_to_count[character] += 1
            counting_to_anagrams[frozenset(character_to_count.items())].append(string)

        return list(counting_to_anagrams.values())

