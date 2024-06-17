class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> sorted_to_anagrams;

        for (const string& str : strs) {
            string key = str;
            sort(key.begin(), key.end());
            sorted_to_anagrams[key].push_back(move(str));
        }

        vector<vector<string>> result;
        result.reserve(sorted_to_anagrams.size());
        for (auto& [sorted, anagrams] : sorted_to_anagrams) {
            result.push_back(move(anagrams));
        }

        return result;
    }
};
