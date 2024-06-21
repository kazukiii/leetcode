class Solution {
public:
    int firstUniqChar(string s) {
        vector<Character> s_with_index;
        for (int i = 0; i < s.size(); i++) {
            s_with_index.push_back({s[i], i});
        }
        sort(s_with_index.begin(), s_with_index.end(), [](const Character& a, const Character& b) {
            return a.character < b.character;
        });

        int count = 1;
        int answer = numeric_limits<int>::max();
        for (int i = 0; i < s_with_index.size(); i++) {
            if (i < s_with_index.size() - 1 && s_with_index[i].character == s_with_index[i + 1].character) {
                count++;
                continue;
            }
            if (count == 1) {
                answer = min(answer, s_with_index[i].index);
            }
            count = 1;
        }

        return answer != numeric_limits<int>::max() ? answer : -1;
    }

private:
    struct Character {
        char character;
        int index;
    };
};
