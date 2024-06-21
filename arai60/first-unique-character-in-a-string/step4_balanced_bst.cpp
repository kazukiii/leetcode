class Solution {
public:
    int firstUniqChar(string s) {
        map<int, char> first_index_to_char;
        unordered_map<char, int> char_to_first_index;
        for (int i = 0; i < s.size(); i++) {
            if (char_to_first_index.find(s[i]) != char_to_first_index.end()) {
                first_index_to_char.erase(char_to_first_index[s[i]]);
                continue;
            }
            first_index_to_char[i] = s[i];
            char_to_first_index[s[i]] = i;
        }

        return !first_index_to_char.empty() ? first_index_to_char.begin()->first : -1;
    }
};
