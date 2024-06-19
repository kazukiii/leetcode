class Solution {
public:
    int firstUniqChar(string s) {
        unordered_map<char, Count> char_to_count;
        for (int i = 0; i < s.size(); ++i) {
            char_to_count[s[i]].count++;
            char_to_count[s[i]].index = i;
        }

        int answer = INT_MAX;
        for (const auto& [num, count]: char_to_count) {
            if (count.count == 1) {
                answer = min(answer, count.index);
            }
        }

        if (answer == INT_MAX) {
            return -1;
        }
        return answer;
    }

private:
    struct Count {
        int count;
        int index;
    };
};
