class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> counting_to_anagrams;

        for (const string& str : strs) {
            array<int, 26> char_count = {0};
            for (char character : str) {
                char_count[character - 'a']++;
            }

            ostringstream oss;
            for (int count : char_count) {
                oss << count << '#';
            }
            string key = oss.str();

            counting_to_anagrams[key].push_back(move(str));
        }

        vector<vector<string>> result;
        result.reserve(counting_to_anagrams.size());
        for (auto& [counting, anagrams] : counting_to_anagrams) {
            result.push_back(move(anagrams));
        }

        return result;
    }
};
